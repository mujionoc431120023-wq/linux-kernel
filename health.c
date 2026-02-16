#include <string.h>
#include <stdio.h>

/* Healthcare AI Module */
int ai_health_analyze(const char *symptom, char *diagnosis) {
    if (strstr(symptom, "batuk")) 
        strcpy(diagnosis, "Kemungkinan: Flu/ISPA, rekomendasi cek dokter.");
    else if (strstr(symptom, "demam")) 
        strcpy(diagnosis, "Kemungkinan: Infeksi, perlu pemeriksaan lebih lanjut.");
    else if (strstr(symptom, "sakit kepala"))
        strcpy(diagnosis, "Kemungkinan: Migrain atau stress, istirahat cukup.");
    else if (strstr(symptom, "sesak"))
        strcpy(diagnosis, "Kemungkinan: Asma atau masalah pernapasan, cek dokter.");
    else 
        strcpy(diagnosis, "Data gejala tidak lengkap, silakan input lebih detail.");
    return 0;
}
