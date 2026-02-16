#include <string.h>

/* Smart City - Transportation AI Module */
int ai_transport_analyze(const char *traffic, char *report) {
    if (strstr(traffic, "macet")) 
        strcpy(report, "AI mendeteksi kemacetan parah, rekomendasi rute alternatif via tol.");
    else if (strstr(traffic, "lancar")) 
        strcpy(report, "Lalu lintas lancar, kecepatan rata-rata optimal, tidak ada hambatan.");
    else if (strstr(traffic, "accident"))
        strcpy(report, "AI mendeteksi kecelakaan, aktifkan emergency services.");
    else if (strstr(traffic, "congestion"))
        strcpy(report, "Kemacetan sedang terdeteksi, reroute traffic otomatis.");
    else 
        strcpy(report, "Data transportasi tidak lengkap atau normal.");
    return 0;
}

/* Smart City - Energy AI Module */
int ai_energy_monitor(const char *usage, char *status) {
    if (strstr(usage, "overload")) 
        strcpy(status, "Konsumsi energi tinggi terdeteksi, aktifkan pembatasan otomatis.");
    else if (strstr(usage, "normal")) 
        strcpy(status, "Energi stabil, sistem berjalan optimal, efisiensi terjaga.");
    else if (strstr(usage, "peak"))
        strcpy(status, "Peak hour terdeteksi, aktivasi demand response program.");
    else if (strstr(usage, "low"))
        strcpy(status, "Konsumsi rendah, mode hemat energi aktif.");
    else 
        strcpy(status, "Data energi tidak dikenali atau normal.");
    return 0;
}

/* Smart City - Environment AI Module */
int ai_env_analyze(const char *sensor, char *result) {
    if (strstr(sensor, "polusi")) 
        strcpy(result, "Polusi udara tinggi terdeteksi, rekomendasi: kurangi kendaraan bermotor.");
    else if (strstr(sensor, "hujan")) 
        strcpy(result, "Curah hujan tinggi, waspada banjir, siapkan evakuasi.");
    else if (strstr(sensor, "temp_anomaly"))
        strcpy(result, "Anomali suhu terdeteksi, mungkin ada perubahan iklim lokal.");
    else if (strstr(sensor, "quality_good"))
        strcpy(result, "Kualitas lingkungan baik, tetap pertahankan kebijakan hijau.");
    else 
        strcpy(result, "Lingkungan normal, tidak ada warning.");
    return 0;
}

/* Smart City - Service AI Module */
int ai_service_request(const char *req, char *resp) {
    if (strstr(req, "ambulance")) 
        strcpy(resp, "Ambulans dikirim ke lokasi Anda, ETA 5 menit.");
    else if (strstr(req, "pemadam")) 
        strcpy(resp, "Pemadam kebakaran dalam perjalanan, keamanan lokasi diprioritaskan.");
    else if (strstr(req, "polisi"))
        strcpy(resp, "Polisi segera dikirim ke lokasi, pastikan keamanan Anda.");
    else if (strstr(req, "maintenance"))
        strcpy(resp, "Tim maintenance dijadwalkan sesuai prioritas.");
    else 
        strcpy(resp, "Permintaan layanan publik tidak dikenali.");
    return 0;
}
