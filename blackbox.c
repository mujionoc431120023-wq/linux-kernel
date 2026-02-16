/* ============================================================
   BLACKBOX LOGGER - System Audit Trail
   Records all AI operations for debugging and security
   ============================================================ */
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define LOG_FILE "data/blackbox.log"

/* Get timestamp string */
static void get_timestamp(char *buf, size_t len) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buf, len, "%Y-%m-%d %H:%M:%S", tm_info);
}

/* Main logging function */
void ai_log_blackbox(const char *level, const char *module, const char *message) {
    if (!level || !module || !message) return;
    
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) return;
    
    char timestamp[64];
    get_timestamp(timestamp, sizeof(timestamp));
    
    fprintf(file, "[%s] [%s] [%s]: %s\n", timestamp, level, module, message);
    fclose(file);
}

/* Log session start */
void ai_log_session_start(void) {
    ai_log_blackbox("INFO", "SYSTEM", "========================================");
    ai_log_blackbox("INFO", "SYSTEM", "OS-MINI AI SESSION STARTED");
    ai_log_blackbox("INFO", "SYSTEM", "========================================");
}

