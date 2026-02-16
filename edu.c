#include <string.h>

/* Education AI Module */
int ai_edu_recommend(const char *topic, char *material) {
    if (strstr(topic, "matematika")) 
        strcpy(material, "Materi: Aljabar dasar, latihan soal persamaan linear, teori fungsi.");
    else if (strstr(topic, "sejarah")) 
        strcpy(material, "Materi: Perang Dunia II, ringkasan kronologi, dampak global.");
    else if (strstr(topic, "fisika"))
        strcpy(material, "Materi: Hukum Newton, kinematika, dinamika sistem partikel.");
    else if (strstr(topic, "bahasa"))
        strcpy(material, "Materi: Tata bahasa, kosakata, latihan percakapan interaktif.");
    else 
        strcpy(material, "Topik pembelajaran tidak tersedia, pilih topik lain.");
    return 0;
}
