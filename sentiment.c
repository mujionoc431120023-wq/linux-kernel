/* ============================================================
   SENTIMENT ANALYSIS - Emotion Detection (ENHANCED)
   Analyzes user emotion from input text
   ============================================================ */
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "../include/ai_hub.h"

/* Sentiment word lists */
typedef struct {
    const char *word;
    int weight;
} sentiment_word_t;

static sentiment_word_t positive_words[] = {
    {"senang", 2}, {"bagus", 2}, {"hebat", 3}, {"suka", 2}, {"good", 2},
    {"happy", 2}, {"love", 3}, {"excellent", 3}, {"awesome", 3}, {"great", 2},
    {"terima kasih", 2}, {"mantap", 2}, {"keren", 2}, {"super", 2}, {"top", 2},
    {"best", 2}, {"nice", 1}, {"amazing", 3}, {"wonderful", 3}, {"perfect", 3},
    {"👍", 1}, {"😊", 1}, {"❤️", 2}, {"🎉", 1}
};

static sentiment_word_t negative_words[] = {
    {"marah", -2}, {"sedih", -2}, {"buruk", -2}, {"jelek", -2}, {"bad", -2},
    {"angry", -2}, {"sad", -2}, {"hate", -3}, {"terrible", -3}, {"awful", -3},
    {"gagal", -2}, {"error", -1}, {"salah", -1}, {"kecewa", -2}, {"frustrasi", -2},
    {"panic", -2}, {"fear", -2}, {"worried", -2}, {"stress", -2}, {" Anxiety", -2},
    {"😠", -1}, {"😢", -1}, {"💔", -2}, {"😱", -2}
};

#define NUM_POSITIVE (sizeof(positive_words) / sizeof(positive_words[0]))
#define NUM_NEGATIVE (sizeof(negative_words) / sizeof(negative_words[0]))

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

/* Analyze sentiment from input */
int ai_analyze_sentiment(const char *input, char *emotion) {
    if (!input || !emotion) return 0;
    
    char lower_input[1024];
    to_lower_copy(input, lower_input, sizeof(lower_input));
    
    int score = 0;
    
    /* Check positive words */
    for (size_t i = 0; i < NUM_POSITIVE; i++) {
        if (strstr(lower_input, positive_words[i].word)) {
            score += positive_words[i].weight;
        }
    }
    
    /* Check negative words */
    for (size_t i = 0; i < NUM_NEGATIVE; i++) {
        if (strstr(lower_input, negative_words[i].word)) {
            score += negative_words[i].weight;
        }
    }
    
    /* Determine emotion label */
    if (score > 2) {
        strcpy(emotion, "Very Positive");
    } else if (score > 0) {
        strcpy(emotion, "Positive");
    } else if (score < -2) {
        strcpy(emotion, "Very Negative");
    } else if (score < 0) {
        strcpy(emotion, "Negative");
    } else {
        strcpy(emotion, "Neutral");
    }
    
    return score;
}

/* Predict next step based on input and emotion */
int ai_predict_next_step(const char *input, const char *emotion, char *prediction) {
    if (!prediction) return -1;
    
    if (!input) {
        strcpy(prediction, "Waiting for input...");
        return 0;
    }
    
    char lower_input[1024];
    to_lower_copy(input, lower_input, sizeof(lower_input));
    
    /* Health-related predictions */
    if (strstr(lower_input, "sakit") || strstr(lower_input, "demam") ||
        strstr(lower_input, "batuk")) {
        strcpy(prediction, "Saran: Mencari informasi kesehatan atau jadwal dokter.");
    }
    /* Finance-related predictions */
    else if (strstr(lower_input, "investasi") || strstr(lower_input, "uang") ||
             strstr(lower_input, "saham")) {
        strcpy(prediction, "Saran: Menampilkan analisis pasar keuangan.");
    }
    /* IoT predictions */
    else if (strstr(lower_input, "nyalakan") || strstr(lower_input, "matikan") ||
             strstr(lower_input, "lampu") || strstr(lower_input, "ac")) {
        strcpy(prediction, "Saran: Mengaktifkan kontrol perangkat IoT.");
    }
    /* Education predictions */
    else if (strstr(lower_input, "belajar") || strstr(lower_input, "materi")) {
        strcpy(prediction, "Saran: Mencari materi pembelajaran yang relevan.");
    }
    /* Negative emotion handling */
    else if (emotion && (strstr(emotion, "Negative") || strstr(emotion, "Very Negative"))) {
        strcpy(prediction, "Saran: Mengaktifkan mode relaksasi atau musik tenang.");
    }
    /* Default prediction */
    else {
        strcpy(prediction, "Menunggu instruksi spesifik selanjutnya.");
    }
    
    return 0;
}

