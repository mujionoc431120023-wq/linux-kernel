/* ============================================================
   MULTI-LANGUAGE DETECTION (ENHANCED)
   Detects language from input using keyword patterns
   ============================================================ */
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "../include/ai_hub.h"

/* Language patterns - common words in each language */
typedef struct {
    const char *code;
    const char *name;
    const char *patterns[15];  /* Support up to 15 patterns */
    int pattern_count;
} language_map_t;

static language_map_t languages[] = {
    {"id", "Indonesian", {"yang", "dan", "dengan", "untuk", "adalah", "ini", "itu", "saya", "aku", "kamu", "panggil", "nama", "sistem"}, 13},
    {"en", "English", {"the", "and", "with", "for", "is", "this", "that", "have", "i", "you", "call", "name", "system"}, 13},
    {"ms", "Malaysian", {"yang", "dan", "dengan", "untuk", "adalah", "ini", "saya", "anda", "aku", "awak"}, 10},
    {"de", "German", {"und", "der", "die", "das", "mit", "für", "ist", "ein"}, 8},
    {"fr", "French", {"le", "la", "les", "et", "dans", "pour", "est", "un"}, 8},
    {"es", "Spanish", {"el", "la", "los", "y", "para", "es", "un", "con"}, 8},
    {"jp", "Japanese", {"watashi", "desu", "anata", "no", "ka", "ga", "wo", "ni"}, 8},
    {"zh", "Chinese", {"de", "shi", "wo", "ni", "he", "zai", "you", "le"}, 8},
    {"ar", "Arabic", {"wa", "al", "il", "bi", "la", "fi", "min", "ana"}, 8},
    {"pt", "Portuguese", {"o", "a", "de", "e", "para", "que", "em", "um"}, 8},
    {"ru", "Russian", {"i", "v", "na", "po", "dlya", "eto", "ne", "ya"}, 8},
    {"ko", "Korean", {"ne", "eun", "reul", "wa", "ge", "eseo", "ida", "nida"}, 8},
    {"th", "Thai", {"khong", "lae", "with", "nai", "th", "pen", "khun", "ra"}, 8},
    {"vi", "Vietnamese", {"va", "la", "cua", "trong", "khong", "toi", "ban", "co"}, 8},
    {"tl", "Tagalog", {"ang", "ng", "sa", "at", "ako", "ikaw", "siya", "kami"}, 8},
    {"hi", "Hindi", {"aur", "hai", "yeh", "woh", "ke", "se", "ka", "ki"}, 8},
    {"nl", "Dutch", {"de", "het", "en", "van", "een", "is", "in", "dat"}, 8},
    {"pl", "Polish", {"i", "to", "jest", "w", "na", "z", "do", "sie"}, 8},
    {"tr", "Turkish", {"ve", "bu", "bir", "ile", "icin", "sonra", "gibi", "ne"}, 8},
    {"it", "Italian", {"e", "la", "il", "di", "che", "un", "per", "non"}, 8}
};

#define NUM_LANGUAGES (sizeof(languages) / sizeof(languages[0]))

/* Convert to lowercase safely */
static void to_lower_copy(const char *src, char *dest, size_t max_len) {
    if (!src || !dest) return;
    size_t len = strlen(src);
    if (len >= max_len) len = max_len - 1;
    for (size_t i = 0; i < len; i++) {
        dest[i] = (char)tolower((unsigned char)src[i]);
    }
    dest[len] = '\0';
}

/* Detect language from input */
int ai_detect_language(const char *input, char *lang_name) {
    if (!input || !lang_name) return -1;
    
    /* Handle empty input */
    if (strlen(input) == 0) {
        strcpy(lang_name, "Unknown");
        return -1;
    }
    
    char lower_input[1024];
    to_lower_copy(input, lower_input, sizeof(lower_input));
    
    int max_hits = 0;
    int detected_idx = 1; /* Default to English */
    
    for (int i = 0; i < NUM_LANGUAGES; i++) {
        int hits = 0;
        for (int j = 0; j < languages[i].pattern_count; j++) {
            if (strstr(lower_input, languages[i].patterns[j])) {
                hits++;
            }
        }
        if (hits > max_hits) {
            max_hits = hits;
            detected_idx = i;
        }
    }
    
    /* Only return language if we have reasonable confidence */
    if (max_hits == 0) {
        strcpy(lang_name, "English (default)");
    } else {
        strcpy(lang_name, languages[detected_idx].name);
    }
    
    return detected_idx;
}

