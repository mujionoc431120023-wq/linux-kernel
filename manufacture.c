#include <string.h>

/* Manufacturing AI Module */
int ai_manufacture_predict(const char *sensor, char *report) {
    if (strstr(sensor, "vibration_high")) 
        strcpy(report, "Mesin bergetar abnormal, prediksi kerusakan dalam 2 hari.");
    else if (strstr(sensor, "temp_high")) 
        strcpy(report, "Suhu mesin tinggi, perlu pendinginan tambahan segera.");
    else if (strstr(sensor, "pressure_drop"))
        strcpy(report, "Tekanan sistem turun, cek kebocoran.");
    else if (strstr(sensor, "vibration_normal"))
        strcpy(report, "Sensor normal, produksi stabil, performa optimal.");
    else 
        strcpy(report, "Data sensor tidak dikenali, kalibrasi ulang diperlukan.");
    return 0;
}
