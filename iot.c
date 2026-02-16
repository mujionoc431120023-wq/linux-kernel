#include <string.h>

/* IoT & Smart Home AI Module */
int ai_iot_process(const char *device, const char *data, char *resp) {
    if (strcmp(device, "smart_home") == 0 && strstr(data, "lamp_on"))
        strcpy(resp, "Lampu rumah sudah menyala, hemat energi aktif.");
    else if (strcmp(device, "smart_home") == 0 && strstr(data, "ac_temp_high"))
        strcpy(resp, "AC terdeteksi panas berlebih, turunkan suhu 2 derajat.");
    else if (strcmp(device, "factory_sensor") == 0 && strstr(data, "overheat"))
        strcpy(resp, "Sensor pabrik mendeteksi panas berlebih, aktifkan pendinginan.");
    else if (strcmp(device, "city_camera") == 0 && strstr(data, "traffic"))
        strcpy(resp, "AI mendeteksi kemacetan, rekomendasi rute alternatif.");
    else 
        strcpy(resp, "Data IoT diterima, tidak ada anomali terdeteksi.");
    return 0;
}
