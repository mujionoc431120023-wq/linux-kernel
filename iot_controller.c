/* ============================================================
   IoT CONTROLLER - Smart Home Control (ENHANCED)
   Manages smart devices with improved device handling
   ============================================================ */
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "../include/ai_hub.h"

#define MAX_DEVICES 10
#define MAX_RESP 512

/* Device status structure */
typedef struct {
    char name[64];
    char type[32];
    int state; /* 0: OFF, 1: ON */
    int brightness; /* 0-100 for dimmable lights */
    float temperature; /* For AC */
    char last_updated[64];
} device_t;

/* Device database */
static device_t devices[MAX_DEVICES] = {
    {"Lampu Ruang Tamu", "light", 0, 50, 0, ""},
    {"Lampu Kamar Tidur", "light", 0, 75, 0, ""},
    {"AC Ruang Tamu", "ac", 0, 0, 24.0, ""},
    {"AC Kamar", "ac", 0, 0, 22.0, ""},
    {"Kipas Angin", "fan", 0, 0, 0, ""},
    {"TV Ruang Tamu", "tv", 0, 0, 0, ""},
    {"Smart Lock", "lock", 0, 0, 0, ""},
    {"Kamera Depan", "camera", 1, 0, 0, ""},
    {"Speaker", "speaker", 0, 0, 0, ""},
    {"Water Heater", "heater", 0, 0, 40.0, ""}
};

static int device_count = 10;

/* Get timestamp */
static void get_timestamp(char *buf, size_t len) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buf, len, "%Y-%m-%d %H:%M:%S", tm_info);
}

/* Convert to lowercase safely */
static void to_lower_inplace(char *str, size_t max_len) {
    if (!str) return;
    size_t len = strlen(str);
    if (len >= max_len) len = max_len - 1;
    for (size_t i = 0; i < len; i++) {
        str[i] = (char)tolower((unsigned char)str[i]);
    }
}

/* Control specific device */
int ai_iot_control(const char *target, int action) {
    if (!target) return 0;
    
    char target_lower[256];
    strncpy(target_lower, target, 255);
    target_lower[255] = '\0';
    to_lower_inplace(target_lower, 256);
    
    int found = 0;
    char log_msg[256];
    
    for (int i = 0; i < device_count; i++) {
        char device_name_lower[256];
        strncpy(device_name_lower, devices[i].name, 255);
        device_name_lower[255] = '\0';
        to_lower_inplace(device_name_lower, 256);
        
        /* Check if target matches device name or type */
        if (strstr(device_name_lower, target_lower) || 
            strstr(devices[i].type, target_lower)) {
            
            devices[i].state = action;
            
            char timestamp[64];
            get_timestamp(timestamp, sizeof(timestamp));
            strncpy(devices[i].last_updated, timestamp, 63);
            devices[i].last_updated[63] = '\0';
            
            snprintf(log_msg, sizeof(log_msg), 
                     "Device '%s' set to %s", 
                     devices[i].name, action ? "ON" : "OFF");
            ai_log_blackbox("INFO", "IOT", log_msg);
            
            found = 1;
        }
    }
    
    return found;
}

/* Get status of all devices */
const char* ai_iot_get_status(void) {
    static char status_report[2048];
    char line[256];
    
    strcpy(status_report, "═══ IoT DEVICE STATUS ═══\n");
    
    for (int i = 0; i < device_count; i++) {
        const char *state_str = devices[i].state ? "ON " : "OFF";
        
        if (strcmp(devices[i].type, "light") == 0) {
            snprintf(line, sizeof(line), "[%s] %s - Brightness: %d%%\n",
                     state_str, devices[i].name, devices[i].brightness);
        } else if (strcmp(devices[i].type, "ac") == 0) {
            snprintf(line, sizeof(line), "[%s] %s - Temp: %.1f°C\n",
                     state_str, devices[i].name, devices[i].temperature);
        } else {
            snprintf(line, sizeof(line), "[%s] %s\n",
                     state_str, devices[i].name);
        }
        strcat(status_report, line);
    }
    
    return status_report;
}

/* Process IoT command */
int ai_iot_process(const char *device, const char *data, char *resp) {
    if (!resp) return 0;
    
    char data_lower[512];
    if (data) {
        strncpy(data_lower, data, 511);
        data_lower[511] = '\0';
        to_lower_inplace(data_lower, 512);
    } else {
        strcpy(data_lower, "");
    }
    
    /* Determine action */
    int action = -1;
    
    if (strstr(data_lower, "nyalakan") || strstr(data_lower, "hidupkan") ||
        strstr(data_lower, "turn on") || strstr(data_lower, "on")) {
        action = 1;
    } else if (strstr(data_lower, "matikan") || strstr(data_lower, "nonaktifkan") ||
               strstr(data_lower, "turn off") || strstr(data_lower, "off")) {
        action = 0;
    }
    
    /* If action is specified, control device */
    if (action >= 0 && device) {
        if (ai_iot_control(device, action)) {
            snprintf(resp, MAX_RESP, "✅ %s telah %s.",
                     device ? device : "Perangkat", 
                     action ? "dinyalakan" : "dimatikan");
        } else {
            snprintf(resp, MAX_RESP, "❌ Perangkat '%s' tidak ditemukan.",
                     device ? device : "");
        }
    } else if (strstr(data_lower, "status") || strstr(data_lower, "cek")) {
        /* Return status of all devices */
        strncpy(resp, ai_iot_get_status(), MAX_RESP - 1);
        resp[MAX_RESP - 1] = '\0';
    } else {
        strcpy(resp, "Perintah IoT tidak dikenali. Coba: 'nyalakan lampu', 'matikan AC', atau 'cek status'.");
    }
    
    return 1;
}

