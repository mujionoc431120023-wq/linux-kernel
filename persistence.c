/* ============================================================
   PERSISTENCE - Long-term Memory (REFACTORED)
   Fixed: Cloud sync integration and atomic write safety
   ============================================================ */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../include/ai_hub.h"

#define MEMORY_PATH "data/ai_memory.dat"
#define MEMORY_BACKUP "data/ai_memory.bak"
#define MAX_RETRIES 3

/* User memory structure */
typedef struct {
    char user_name[50];
    char last_topic[50];
    int interaction_count;
    char user_preference[256];
    char last_domain[32];
    int version;
    unsigned int checksum;
} long_term_memory_t;

static long_term_memory_t ltm;
static int memory_loaded = 0;
static int memory_dirty = 0;

/* Encryption key */
static const char *ENCRYPTION_KEY = "OS_MINI_OMEGA_SECURE_KEY_2026";

/* Calculate checksum */
static unsigned int calculate_checksum(const long_term_memory_t *mem) {
    unsigned int sum = 0;
    const char *data = (const char *)mem;
    for (size_t i = 0; i < sizeof(long_term_memory_t) - sizeof(unsigned int); i++) {
        sum += (unsigned char)data[i];
    }
    return sum;
}

/* Simple XOR encryption */
void ai_crypto_process(char *data, size_t len) {
    if (!data || len == 0) return;
    size_t key_len = strlen(ENCRYPTION_KEY);
    for (size_t i = 0; i < len; i++) {
        data[i] ^= ENCRYPTION_KEY[i % key_len];
    }
}

/* Ensure data directory exists */
static int ensure_data_dir(void) {
    struct stat st = {0};
    if (stat("data", &st) == -1) {
        if (mkdir("data", 0700) != 0) {
            ai_log_blackbox("ERROR", "PERSISTENCE", "Failed to create data directory");
            return 0;
        }
    }
    return 1;
}

/* Create backup */
static int create_backup(void) {
    if (access(MEMORY_PATH, F_OK) != 0) return 0;
    
    FILE *src = fopen(MEMORY_PATH, "rb");
    if (!src) return 0;
    
    FILE *dst = fopen(MEMORY_BACKUP, "wb");
    if (!dst) { fclose(src); return 0; }
    
    char buffer[4096];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dst);
    }
    
    fclose(src);
    fclose(dst);
    return 1;
}

/* Load memory with retry logic */
void ai_persistence_load(void) {
    if (memory_loaded) return;
    
    if (!ensure_data_dir()) {
        memset(&ltm, 0, sizeof(long_term_memory_t));
        strcpy(ltm.user_name, "User");
        ltm.version = 1;
        memory_loaded = 1;
        return;
    }
    
    FILE *file = fopen(MEMORY_PATH, "rb");
    if (file) {
        long_term_memory_t temp_mem;
        size_t read_size = fread(&temp_mem, sizeof(long_term_memory_t), 1, file);
        fclose(file);
        
        if (read_size > 0) {
            ai_crypto_process((char *)&temp_mem, sizeof(long_term_memory_t));
            
            unsigned int stored_checksum = temp_mem.checksum;
            temp_mem.checksum = 0;
            unsigned int calc_checksum = calculate_checksum(&temp_mem);
            
            if (stored_checksum == calc_checksum) {
                memcpy(&ltm, &temp_mem, sizeof(long_term_memory_t));
                ai_log_blackbox("INFO", "PERSISTENCE", "Memory loaded and verified");
                memory_loaded = 1;
                return;
            } else {
                ai_log_blackbox("WARN", "PERSISTENCE", "Checksum mismatch, trying backup");
                file = fopen(MEMORY_BACKUP, "rb");
                if (file) {
                    read_size = fread(&temp_mem, sizeof(long_term_memory_t), 1, file);
                    fclose(file);
                    if (read_size > 0) {
                        ai_crypto_process((char *)&temp_mem, sizeof(long_term_memory_t));
                        if (calculate_checksum(&temp_mem) == temp_mem.checksum) {
                            memcpy(&ltm, &temp_mem, sizeof(long_term_memory_t));
                            ai_log_blackbox("INFO", "PERSISTENCE", "Restored from backup");
                            memory_loaded = 1;
                            return;
                        }
                    }
                }
            }
        }
    }
    
    /* Initialize new */
    memset(&ltm, 0, sizeof(long_term_memory_t));
    strcpy(ltm.user_name, "User");
    ltm.interaction_count = 0;
    ltm.version = 1;
    ltm.checksum = calculate_checksum(&ltm);
    
    ai_log_blackbox("WARN", "PERSISTENCE", "New memory initialized");
    memory_loaded = 1;
    ai_persistence_save();
}

/* Save with atomic write */
void ai_persistence_save(void) {
    if (!memory_loaded) return;
    
    if (!ensure_data_dir()) return;
    
    /* Create backup first */
    create_backup();
    
    ltm.checksum = calculate_checksum(&ltm);
    
    /* Atomic write: write to temp, then rename */
    char temp_path[256];
    snprintf(temp_path, sizeof(temp_path), "%s.tmp", MEMORY_PATH);
    
    FILE *file = fopen(temp_path, "wb");
    if (!file) {
        ai_log_blackbox("ERROR", "PERSISTENCE", "Failed to create temp file");
        return;
    }
    
    long_term_memory_t temp_mem = ltm;
    ai_crypto_process((char *)&temp_mem, sizeof(long_term_memory_t));
    
    size_t written = fwrite(&temp_mem, sizeof(long_term_memory_t), 1, file);
    fflush(file);
    fclose(file);
    
    if (written > 0) {
        if (rename(temp_path, MEMORY_PATH) == 0) {
            ai_log_blackbox("DEBUG", "PERSISTENCE", "Memory saved successfully");
            memory_dirty = 0;
        } else {
            ai_log_blackbox("ERROR", "PERSISTENCE", "Failed to rename temp file");
            unlink(temp_path);
        }
    } else {
        ai_log_blackbox("ERROR", "PERSISTENCE", "Failed to write memory");
        unlink(temp_path);
    }
}

/* Update memory */
void ai_persistence_update(const char *key, const char *value) {
    if (!key || !value) return;
    
    if (strcmp(key, "name") == 0) {
        strncpy(ltm.user_name, value, 49);
        ltm.user_name[49] = '\0';
    } else if (strcmp(key, "topic") == 0) {
        strncpy(ltm.last_topic, value, 49);
        ltm.last_topic[49] = '\0';
    } else if (strcmp(key, "domain") == 0) {
        strncpy(ltm.last_domain, value, 31);
        ltm.last_domain[31] = '\0';
    } else if (strcmp(key, "pref") == 0) {
        strncpy(ltm.user_preference, value, 255);
        ltm.user_preference[255] = '\0';
    }
    
    ltm.interaction_count++;
    memory_dirty = 1;
    ai_persistence_save();
}

char* ai_get_user_name(void) {
    return ltm.user_name;
}

