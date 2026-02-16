#include <string.h>

/* Finance AI Module */
int ai_finance_analyze(const char *transaction, char *result) {
    if (strstr(transaction, "jumlah besar")) 
        strcpy(result, "Transaksi mencurigakan, perlu verifikasi manual segera.");
    else if (strstr(transaction, "investasi")) 
        strcpy(result, "Rekomendasi: Diversifikasi ke saham, obligasi, dan REIT.");
    else if (strstr(transaction, "regular"))
        strcpy(result, "Transaksi regular terdeteksi, pola normal terjaga.");
    else if (strstr(transaction, "foreign"))
        strcpy(result, "Transaksi luar negeri terdeteksi, terapkan fee exchange.");
    else 
        strcpy(result, "Transaksi normal, tidak ada anomali terdeteksi.");
    return 0;
}
