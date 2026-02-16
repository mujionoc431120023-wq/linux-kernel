/* ============================================================
   CONTEXT-AWARE SWITCHING (REFACTORED)
   Fixed: Added more IoT keywords for better auto-switching
   ============================================================ */
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/ai_hub.h"

#define MAX_CONTEXT_HISTORY 10
#define CONTEXT_STR_LEN 512

/* Context history storage */
static struct {
    char history[MAX_CONTEXT_HISTORY][CONTEXT_STR_LEN];
    int current_idx;
    int history_count;
    char current_intent[64];
    char previous_intent[64];
} context_mem = { 
    .current_idx = 0, 
    .history_count = 0,
    .current_intent = "general",
    .previous_intent = "general"
};

/* Convert to lowercase safely */
static void to_lower_inplace(char *str, size_t max_len) {
    if (!str) return;
    size_t len = strlen(str);
    if (len >= max_len) len = max_len - 1;
    for (size_t i = 0; i < len; i++) {
        str[i] = (char)tolower((unsigned char)str[i]);
    }
}

/* Update context based on input keywords */
void ai_context_update(const char *input) {
    if (!input) return;
    
    /* Store previous intent */
    strncpy(context_mem.previous_intent, context_mem.current_intent, 63);
    context_mem.previous_intent[63] = '\0';
    
    char lower_input[CONTEXT_STR_LEN];
    strncpy(lower_input, input, CONTEXT_STR_LEN - 1);
    lower_input[CONTEXT_STR_LEN - 1] = '\0';
    to_lower_inplace(lower_input, CONTEXT_STR_LEN);
    
    /* Priority-based topic detection */
    
    /* HEALTH - Highest priority */
    if (strstr(lower_input, "sakit") || strstr(lower_input, "obat") || 
        strstr(lower_input, "diagnosa") || strstr(lower_input, "demam") ||
        strstr(lower_input, "batuk") || strstr(lower_input, "pusing") ||
        strstr(lower_input, "flu") || strstr(lower_input, "health") ||
        strstr(lower_input, "medis") || strstr(lower_input, "dokter") ||
        strstr(lower_input, "sehat") || strstr(lower_input, "penyakit")) {
        strcpy(context_mem.current_intent, "health");
    }
    /* IOT/SMART HOME - Fixed keywords */
    else if (strstr(lower_input, "iot") || strstr(lower_input, "smart home") || 
             strstr(lower_input, "lampu") || strstr(lower_input, "ac ") ||
             strstr(lower_input, "nyalakan") || strstr(lower_input, "matikan") ||
             strstr(lower_input, "hidupkan") || strstr(lower_input, "nonaktifkan") ||
             strstr(lower_input, "kipas") || strstr(lower_input, "tv ") ||
             strstr(lower_input, "kunci") || strstr(lower_input, "kamera") ||
             strstr(lower_input, "speaker") || strstr(lower_input, "heater") ||
             strstr(lower_input, "smartdevice") || strstr(lower_input, "perangkat") ||
             strstr(lower_input, "turn on") || strstr(lower_input, "turn off") ||
             strstr(lower_input, "switch") || strstr(lower_input, "device")) {
        strcpy(context_mem.current_intent, "iot");
    }
    /* FINANCE */
    else if (strstr(lower_input, "investasi") || strstr(lower_input, "uang") || 
             strstr(lower_input, "dana") || strstr(lower_input, "saham") ||
             strstr(lower_input, "keuangan") || strstr(lower_input, "finance") ||
             strstr(lower_input, "bank") || strstr(lower_input, "kredit")) {
        strcpy(context_mem.current_intent, "finance");
    }
    /* DESTINY */
    else if (strstr(lower_input, "masa depan") || strstr(lower_input, "ramalan") || 
             strstr(lower_input, "takdir") || strstr(lower_input, "destiny") ||
             strstr(lower_input, "fortune") || strstr(lower_input, "nasib")) {
        strcpy(context_mem.current_intent, "destiny");
    }
    /* COSMIC */
    else if (strstr(lower_input, "alam semesta") || strstr(lower_input, "quantum") || 
             strstr(lower_input, "kosmik") || strstr(lower_input, "cosmic") ||
             strstr(lower_input, "galaxy") || strstr(lower_input, "angkasa")) {
        strcpy(context_mem.current_intent, "cosmic");
    }
    /* EDUCATION */
    else if (strstr(lower_input, "belajar") || strstr(lower_input, "sekolah") || 
             strstr(lower_input, "kampus") || strstr(lower_input, "ajar") ||
             strstr(lower_input, "education") || strstr(lower_input, "materi") ||
             strstr(lower_input, "kuliah") || strstr(lower_input, "kursus")) {
        strcpy(context_mem.current_intent, "education");
    }
    /* SMART CITY */
    else if (strstr(lower_input, "kota") || strstr(lower_input, "lalu lintas") || 
             strstr(lower_input, "energi") || strstr(lower_input, "transport") ||
             strstr(lower_input, "macet") || strstr(lower_input, "smartcity") ||
             strstr(lower_input, "polusi") || strstr(lower_input, "lingkungan")) {
        strcpy(context_mem.current_intent, "smartcity");
    }
    /* CODEAGENT */
    else if (strstr(lower_input, "kode") || strstr(lower_input, "coding") || 
             strstr(lower_input, "program") || strstr(lower_input, "debug") ||
             strstr(lower_input, "algorithm") || strstr(lower_input, "codeagent") ||
             strstr(lower_input, "function") || strstr(lower_input, "syntax")) {
        strcpy(context_mem.current_intent, "codeagent");
    }
    /* GOVERNANCE */
    else if (strstr(lower_input, "governance") || strstr(lower_input, "kebijakan") ||
             strstr(lower_input, "compliance") || strstr(lower_input, "hukum") ||
             strstr(lower_input, "aturan") || strstr(lower_input, "peraturan")) {
        strcpy(context_mem.current_intent, "governance");
    }
    /* MANUFACTURING */
    else if (strstr(lower_input, "manufacture") || strstr(lower_input, "pabrik") ||
             strstr(lower_input, "mesin") || strstr(lower_input, "factory") ||
             strstr(lower_input, "sensor") || strstr(lower_input, "maintenance")) {
        strcpy(context_mem.current_intent, "manufacturing");
    }
    /* SYMBIOSIS */
    else if (strstr(lower_input, "symbiosis") || strstr(lower_input, "transhuman") ||
             strstr(lower_input, "biointerface") || strstr(lower_input, "neuro")) {
        strcpy(context_mem.current_intent, "symbiosis");
    }
    /* Keep previous intent if no match */
    
    /* Save to history (FIFO) */
    if (context_mem.current_idx >= MAX_CONTEXT_HISTORY) {
        for (int i = 0; i < MAX_CONTEXT_HISTORY - 1; i++) {
            strncpy(context_mem.history[i], context_mem.history[i + 1], CONTEXT_STR_LEN - 1);
            context_mem.history[i][CONTEXT_STR_LEN - 1] = '\0';
        }
        context_mem.current_idx = MAX_CONTEXT_HISTORY - 1;
    }
    
    strncpy(context_mem.history[context_mem.current_idx], input, CONTEXT_STR_LEN - 1);
    context_mem.history[context_mem.current_idx][CONTEXT_STR_LEN - 1] = '\0';
    context_mem.current_idx++;
    if (context_mem.history_count < MAX_CONTEXT_HISTORY) {
        context_mem.history_count++;
    }
}

/* Get current context intent */
const char* ai_context_get_current(void) {
    return context_mem.current_intent;
}

/* Reset context */
void ai_context_reset(void) {
    context_mem.current_idx = 0;
    context_mem.history_count = 0;
    strcpy(context_mem.current_intent, "general");
    strcpy(context_mem.previous_intent, "general");
}

/* Check if current context is about a specific topic */
int ai_context_is_about(const char *keyword) {
    if (!keyword) return 0;
    
    char keyword_lower[128];
    strncpy(keyword_lower, keyword, 127);
    keyword_lower[127] = '\0';
    to_lower_inplace(keyword_lower, 128);
    
    for (int i = 0; i < context_mem.history_count; i++) {
        if (strstr(context_mem.history[i], keyword_lower)) {
            return 1;
        }
    }
    return 0;
}

