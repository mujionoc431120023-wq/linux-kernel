/* ============================================================
   FUZZY LOGIC - Anti-Typo System (ENHANCED)
   Uses Levenshtein Distance algorithm with optimization
   ============================================================ */
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/ai_hub.h"

/* Calculate minimum of three values */
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

/* Calculate Levenshtein distance between two strings */
int ai_fuzzy_distance(const char *s1, const char *s2) {
    if (!s1 || !s2) return -1;
    
    int s1len = (int)strlen(s1);
    int s2len = (int)strlen(s2);
    
    /* Handle empty strings */
    if (s1len == 0) return s2len;
    if (s2len == 0) return s1len;
    
    /* Limit max distance to prevent excessive computation */
    if (s1len > 100 || s2len > 100) {
        s1len = 100;
        s2len = 100;
    }
    
    /* Allocate matrix on stack */
    int matrix[101][101];
    
    /* Initialize first row and column */
    matrix[0][0] = 0;
    for (int x = 1; x <= s1len; x++) matrix[x][0] = x;
    for (int y = 1; y <= s2len; y++) matrix[0][y] = y;

    /* Fill in the rest of the matrix */
    for (int x = 1; x <= s1len; x++) {
        for (int y = 1; y <= s2len; y++) {
            int cost = (s1[x - 1] == s2[y - 1]) ? 0 : 1;
            matrix[x][y] = MIN3(
                matrix[x - 1][y] + 1,           /* deletion */
                matrix[x][y - 1] + 1,           /* insertion */
                matrix[x - 1][y - 1] + cost    /* substitution */
            );
        }
    }
    return matrix[s1len][s2len];
}

/* Convert string to lowercase safely */
static void to_lower_copy(const char *src, char *dest, size_t max_len) {
    if (!src || !dest) return;
    
    size_t len = strlen(src);
    if (len >= max_len) len = max_len - 1;
    
    for (size_t i = 0; i < len; i++) {
        dest[i] = (char)tolower((unsigned char)src[i]);
    }
    dest[len] = '\0';
}

/* Check if two strings are similar (within tolerance) */
int ai_fuzzy_match(const char *input, const char *target) {
    if (!input || !target) return 0;
    
    /* Empty check */
    if (strlen(input) == 0 || strlen(target) == 0) return 0;
    
    /* Exact match */
    if (strcmp(input, target) == 0) return 1;
    
    /* Allocate lowercase copies */
    char input_lower[256];
    char target_lower[256];
    
    to_lower_copy(input, input_lower, sizeof(input_lower));
    to_lower_copy(target, target_lower, sizeof(target_lower));
    
    /* Case-insensitive exact match */
    if (strcmp(input_lower, target_lower) == 0) return 1;
    
    /* Fuzzy match with tolerance based on target length */
    int distance = ai_fuzzy_distance(input_lower, target_lower);
    if (distance < 0) return 0;
    
    int tolerance = 2;
    size_t target_len = strlen(target);
    if (target_len > 5) tolerance = 3;
    if (target_len > 10) tolerance = 4;
    if (target_len > 15) tolerance = 5;
    
    return (distance <= tolerance) ? 1 : 0;
}

