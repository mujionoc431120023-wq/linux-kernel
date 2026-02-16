/* ============================================================
   OS-MINI AI - Main Entry Point
   Enhanced with Context-Aware Intelligence & Self-Repair
   ============================================================ */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/ai_hub.h"

/* Color codes for terminal */
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

/* Print welcome banner */
void print_banner(void) {
    printf(BOLD CYAN);
    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║           OS-MINI AI OMEGA v1.0.0                         ║\n");
    printf("║           Multi-Domain Intelligence System                  ║\n");
    printf("║           Powered by CodeAgent & Self-Repair             ║\n");
    printf("╚═══════════════════════════════════════════════════════════════╝\n");
    printf(RESET);
}

/* Print main menu */
void print_menu(void) {
    printf(BOLD YELLOW "\n═══ PILIH DOMAIN AI ===" RESET "\n");
    printf(BLUE "  [1]" RESET " Healthcare     - Analisis kesehatan & diagnosis\n");
    printf(BLUE "  [2]" RESET " Education      - Rekomendasi materi pembelajaran\n");
    printf(BLUE "  [3]" RESET " Finance        - Analisis transaksi keuangan\n");
    printf(BLUE "  [4]" RESET " Manufacturing  - Prediksi maintenance mesin\n");
    printf(BLUE "  [5]" RESET " IoT            - Smart home control\n");
    printf(BLUE "  [6]" RESET " Smart City     - Transportasi, energi, lingkungan\n");
    printf(BLUE "  [7]" RESET " Governance     - Compliance & kebijakan\n");
    printf(BLUE "  [8]" RESET " Future AI      - Quantum, Neuromorphic, Autonomous\n");
    printf(MAGENTA "  [9]" RESET " CodeAgent      - Analisis & generasi kode\n");
    printf(CYAN "  [10]" RESET " Destiny        - Masa depan & takdir\n");
    printf(CYAN "  [11]" RESET " IoT Status     - Cek status semua device\n");
    printf(YELLOW "  [12]" RESET " Context Info   - Lihat konteks & sentiment\n");
    printf(BOLD GREEN "  [13]" RESET " Self-Repair    - Auto fix bug & health check\n");
    printf(BOLD RED "  [0]" RESET " Exit\n");
    printf(BOLD GREEN "\n>>> " RESET);
}

/* Handle healthcare */
void handle_health(void) {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    
    printf(CYAN "\n=== HEALTHCARE AI ===" RESET "\n");
    printf("Masukkan gejala (例: batuk, demam, sakit kepala, sesak): ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;
    
    ai_health_analyze(input, output);
    printf(GREEN "\n📋 Diagnosis: %s\n" RESET, output);
}

/* Handle education */
void handle_education(void) {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    
    printf(CYAN "\n=== EDUCATION AI ===" RESET "\n");
    printf("Masukkan topik (例: matematika, sejarah, fisika, programming): ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;
    
    ai_edu_recommend(input, output);
    printf(GREEN "\n📚 Materi: %s\n" RESET, output);
}

/* Handle finance */
void handle_finance(void) {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    
    printf(CYAN "\n=== FINANCE AI ===" RESET "\n");
    printf("Masukkan transaksi (例: investasi, jumlah besar, regular, crypto): ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;
    
    ai_finance_analyze(input, output);
    printf(GREEN "\n💰 Analisis: %s\n" RESET, output);
}

/* Handle manufacturing */
void handle_manufacturing(void) {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    
    printf(CYAN "\n=== MANUFACTURING AI ===" RESET "\n");
    printf("Masukkan data sensor (例: vibration_high, temp_high, pressure_drop): ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;
    
    ai_manufacture_predict(input, output);
    printf(GREEN "\n🏭 Laporan: %s\n" RESET, output);
}

/* Handle IoT */
void handle_iot(void) {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    
    printf(CYAN "\n=== IoT AI ===" RESET "\n");
    printf("Masukkan perintah (例: nyalakan lampu, matikan AC, status): ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;
    
    ai_iot_process("smart_home", input, output);
    printf(GREEN "\n🏠 Status: %s\n" RESET, output);
}

/* Handle smart city */
void handle_smartcity(void) {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    int submenu;
    
    printf(CYAN "\n=== SMART CITY AI ===" RESET "\n");
    printf("  [1] Transportasi\n");
    printf("  [2] Energi\n");
    printf("  [3] Lingkungan\n");
    printf("  [4] Layanan Publik\n");
    printf("Pilih: ");
    scanf("%d", &submenu);
    getchar();
    
    switch(submenu) {
        case 1:
            printf("Data lalu lintas (例: macet, lancar, accident): ");
            fgets(input, MAX_INPUT, stdin);
            input[strcspn(input, "\n")] = 0;
            ai_transport_analyze(input, output);
            printf(GREEN "\n🚗 Laporan: %s\n" RESET, output);
            break;
        case 2:
            printf("Data energi (例: overload, normal, peak, low): ");
            fgets(input, MAX_INPUT, stdin);
            input[strcspn(input, "\n")] = 0;
            ai_energy_monitor(input, output);
            printf(GREEN "\n⚡ Status: %s\n" RESET, output);
            break;
        case 3:
            printf("Data lingkungan (例: polusi, hujan, temp_anomaly): ");
            fgets(input, MAX_INPUT, stdin);
            input[strcspn(input, "\n")] = 0;
            ai_env_analyze(input, output);
            printf(GREEN "\n🌍 Hasil: %s\n" RESET, output);
            break;
        case 4:
            printf("Permintaan layanan (例: ambulance, pemadam, polisi): ");
            fgets(input, MAX_INPUT, stdin);
            input[strcspn(input, "\n")] = 0;
            ai_service_request(input, output);
            printf(GREEN "\n🚑 Respons: %s\n" RESET, output);
            break;
        default:
            printf(RED "Pilihan tidak valid!\n" RESET);
    }
}

/* Handle governance */
void handle_governance(void) {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    
    printf(CYAN "\n=== GOVERNANCE AI ===" RESET "\n");
    printf("Masukkan kebijakan (例: privacy, security, finance, labor): ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;
    
    ai_governance_check(input, output);
    printf(GREEN "\n⚖️ Compliance: %s\n" RESET, output);
}

/* Handle future AI */
void handle_future(void) {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    int submenu;
    
    printf(CYAN "\n=== FUTURE AI ===" RESET "\n");
    printf("  [1] Quantum Optimization\n");
    printf("  [2] Neuromorphic Processing\n");
    printf("  [3] Autonomous Control\n");
    printf("  [4] Self-Learning\n");
    printf("  [5] Adaptive Context\n");
    printf("Pilih: ");
    scanf("%d", &submenu);
    getchar();
    
    switch(submenu) {
        case 1:
            printf("Problem (例: routing, finance, optimization): ");
            fgets(input, MAX_INPUT, stdin);
            input[strcspn(input, "\n")] = 0;
            ai_quantum_optimize(input, output);
            break;
        case 2:
            printf("Signal (例: pattern, sensor, learning): ");
            fgets(input, MAX_INPUT, stdin);
            input[strcspn(input, "\n")] = 0;
            ai_neuro_process(input, output);
            break;
        case 3:
            printf("Command (例: drive, fly, operate): ");
            fgets(input, MAX_INPUT, stdin);
            input[strcspn(input, "\n")] = 0;
            ai_autonomous_control(input, output);
            break;
        case 4:
            printf("Feedback (例: positif, negatif): ");
            fgets(input, MAX_INPUT, stdin);
            input[strcspn(input, "\n")] = 0;
            ai_self_learn(input, "general", output);
            break;
        case 5:
            printf("Context (例: malam, kerja, relaksasi): ");
            fgets(input, MAX_INPUT, stdin);
            input[strcspn(input, "\n")] = 0;
            ai_adapt_context(input, output);
            break;
        default:
            printf(RED "Pilihan tidak valid!\n" RESET);
            return;
    }
    printf(GREEN "\n🔮 Result: %s\n" RESET, output);
}

/* Handle CodeAgent */
void handle_codeagent(void) {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    int submenu;
    
    while (1) {
        printf(BOLD MAGENTA "\n═══ CODEAGENT ===" RESET "\n");
        printf(BLUE "  [1]" RESET " Analyze     - Analisis tugas coding\n");
        printf(BLUE "  [2]" RESET " Generate    - Generate kode\n");
        printf(BLUE "  [3]" RESET " Debug       - Debug & fix error\n");
        printf(BLUE "  [4]" RESET " Review      - Code review\n");
        printf(BLUE "  [5]" RESET " Optimize    - Optimasi kode\n");
        printf(BLUE "  [6]" RESET " Explain     - Jelaskan kode\n");
        printf(BOLD RED "  [0]" RESET " Back\n");
        printf(BOLD GREEN "\n>>> " RESET);
        
        if (scanf("%d", &submenu) != 1) {
            printf(RED "Invalid input!\n" RESET);
            break;
        }
        getchar();
        
        if (submenu == 0) break;
        
        switch(submenu) {
            case 1:
                printf(CYAN "\n=== ANALYZE ===" RESET "\n");
                printf("Masukkan tugas (algorithm, data structure, performance, security, api, testing): ");
                fgets(input, MAX_INPUT, stdin);
                input[strcspn(input, "\n")] = 0;
                ai_codeagent_analyze(input, output);
                printf(GREEN "\n📊 Analysis: %s\n" RESET, output);
                break;
                
            case 2:
                printf(CYAN "\n=== GENERATE ===" RESET "\n");
                printf("Pilih bahasa [1] C [2] Python [3] JavaScript: ");
                int lang;
                scanf("%d", &lang);
                getchar();
                
                char lang_str[32];
                if (lang == 1) strcpy(lang_str, "c");
                else if (lang == 2) strcpy(lang_str, "python");
                else if (lang == 3) strcpy(lang_str, "javascript");
                else { printf(RED "Invalid!\n" RESET); break; }
                
                printf("Requirements (例: linked list, api server, web server, machine learning): ");
                fgets(input, MAX_INPUT, stdin);
                input[strcspn(input, "\n")] = 0;
                
                ai_codeagent_generate(lang_str, input, output);
                printf(GREEN "\n💻 Generated Code:\n\n%s\n" RESET, output);
                break;
                
            case 3:
                printf(CYAN "\n=== DEBUG ===" RESET "\n");
                printf("Masukkan error (null pointer, segmentation fault, memory leak, sql injection): ");
                fgets(input, MAX_INPUT, stdin);
                input[strcspn(input, "\n")] = 0;
                ai_codeagent_debug("", input, output);
                printf(GREEN "\n🔧 Fix: %s\n" RESET, output);
                break;
                
            case 4:
                printf(CYAN "\n=== REVIEW ===" RESET "\n");
                printf("Masukkan kode atau keyword (goto, malloc, eval, SELECT): ");
                fgets(input, MAX_INPUT, stdin);
                input[strcspn(input, "\n")] = 0;
                ai_codeagent_review(input, output);
                printf(GREEN "\n📝 Review: %s\n" RESET, output);
                break;
                
            case 5:
                printf(CYAN "\n=== OPTIMIZE ===" RESET "\n");
                printf("Masukkan pattern (SELECT *, String+, ArrayList): ");
                fgets(input, MAX_INPUT, stdin);
                input[strcspn(input, "\n")] = 0;
                ai_codeagent_optimize(input, output);
                printf(GREEN "\n⚡ Optimization: %s\n" RESET, output);
                break;
                
            case 6:
                printf(CYAN "\n=== EXPLAIN ===" RESET "\n");
                printf("Masukkan kode (struct, pthread, SELECT, def, class, async): ");
                fgets(input, MAX_INPUT, stdin);
                input[strcspn(input, "\n")] = 0;
                ai_codeagent_explain(input, output);
                printf(GREEN "\n📖 Explanation: %s\n" RESET, output);
                break;
                
            default:
                printf(RED "Pilihan tidak valid!\n" RESET);
        }
        
        printf(YELLOW "\nTekan Enter..." RESET);
        getchar();
    }
}

/* Handle destiny */
void handle_destiny(void) {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    
    printf(CYAN "\n=== DESTINY AI ===" RESET "\n");
    printf("Masukkan pertanyaan tentang masa depan: ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;
    
    ai_destiny_core(input, output);
    printf(GREEN "\n✨ Destiny: %s\n" RESET, output);
}

/* Handle IoT status */
void handle_iot_status(void) {
    char output[MAX_OUTPUT];
    
    printf(CYAN "\n=== IoT DEVICE STATUS ===" RESET "\n");
    strcpy(output, ai_iot_get_status());
    printf(GREEN "%s\n" RESET, output);
}

/* Handle context info */
void handle_context_info(void) {
    char lang[32] = "Unknown";
    char emotion[32] = "Neutral";
    char prediction[128] = "None";
    const char *context;
    
    printf(CYAN "\n=== CONTEXT & SENTIMENT INFO ===" RESET "\n");
    
    /* Get current context */
    context = ai_context_get_current();
    printf(GREEN "Current Context: %s\n" RESET, context);
    
    /* Show user info from persistence */
    printf(GREEN "User: %s\n" RESET, ai_get_user_name());
    
    /* Predict next step based on context */
    ai_predict_next_step("", "neutral", prediction);
    printf(GREEN "AI Prediction: %s\n" RESET, prediction);
}

/* Handle Self-Repair */
void handle_self_repair(void) {
    int submenu;
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    
    while (1) {
        printf(BOLD GREEN "\n═══ SELF-REPAIR SYSTEM ===" RESET "\n");
        printf(BLUE "  [1]" RESET " Health Check     - Cek kondisi sistem\n");
        printf(BLUE "  [2]" RESET " Run Diagnostics  - Jalankan diagnosa lengkap\n");
        printf(BLUE "  [3]" RESET " View Errors      - Lihat semua error\n");
        printf(BLUE "  [4]" RESET " Auto-Fix         - Perbaiki error otomatis\n");
        printf(BLUE "  [5]" RESET " Analyze Error    - Analisis error tertentu\n");
        printf(BLUE "  [6]" RESET " Restore Backup   - Pulihkan dari backup\n");
        printf(BLUE "  [7]" RESET " Clear Errors     - Hapus log error\n");
        printf(BLUE "  [8]" RESET " Simulate Error   - Uji deteksi error\n");
        printf(BOLD RED "  [0]" RESET " Back\n");
        printf(BOLD GREEN "\n>>> " RESET);
        
        if (scanf("%d", &submenu) != 1) {
            printf(RED "Invalid input!\n" RESET);
            break;
        }
        getchar();
        
        if (submenu == 0) break;
        
        switch(submenu) {
            case 1: /* Health Check */
                printf(CYAN "\n=== HEALTH CHECK ===" RESET "\n");
                ai_self_repair_get_health_status(output, MAX_OUTPUT);
                printf(GREEN "%s\n" RESET, output);
                break;
                
            case 2: /* Run Diagnostics */
                printf(CYAN "\n=== RUNNING DIAGNOSTICS ===" RESET "\n");
                ai_self_repair_run_diagnostics(output, MAX_OUTPUT);
                printf(GREEN "%s\n" RESET, output);
                break;
                
            case 3: /* View Errors */
                printf(CYAN "\n=== ERROR LIST ===" RESET "\n");
                int error_count = ai_self_repair_get_error_count();
                int unfixed = ai_self_repair_get_unfixed_count();
                printf("Total Errors: %d\n", error_count);
                printf("Unfixed: %d\n", unfixed);
                if (error_count > 0 && unfixed > 0) {
                    printf("\nKetik nomor error untuk analisis: ");
                    int err_id;
                    scanf("%d", &err_id);
                    getchar();
                    ai_self_repair_analyze_error(err_id, output, MAX_OUTPUT);
                    printf(GREEN "%s\n" RESET, output);
                }
                break;
                
            case 4: /* Auto-Fix */
                printf(CYAN "\n=== AUTO-FIX ===" RESET "\n");
                int unfixed_count = ai_self_repair_get_unfixed_count();
                if (unfixed_count > 0) {
                    printf("Mencoba memperbaiki %d error...\n", unfixed_count);
                    /* Auto-fix all unfixed errors */
                    for (int i = 1; i <= error_count; i++) {
                        ai_self_repair_auto_fix(i);
                    }
                    printf(GREEN "Auto-fix selesai!\n" RESET);
                } else {
                    printf(YELLOW "Tidak ada error yang perlu diperbaiki.\n" RESET);
                }
                break;
                
            case 5: /* Analyze Error */
                printf(CYAN "\n=== ANALYZE ERROR ===" RESET "\n");
                printf("Masukkan ID error: ");
                int analyze_id;
                scanf("%d", &analyze_id);
                getchar();
                ai_self_repair_analyze_error(analyze_id, output, MAX_OUTPUT);
                printf(GREEN "%s\n" RESET, output);
                break;
                
            case 6: /* Restore Backup */
                printf(CYAN "\n=== RESTORE BACKUP ===" RESET "\n");
                printf("Mencoba memulihkan dari backup...\n");
                int restore_result = ai_self_repair_restore_backup();
                if (restore_result == 0) {
                    printf(GREEN "Berhasil memulihkan dari backup!\n" RESET);
                } else {
                    printf(RED "Gagal memulihkan - backup tidak ditemukan.\n" RESET);
                }
                break;
                
            case 7: /* Clear Errors */
                printf(CYAN "\n=== CLEAR ERRORS ===" RESET "\n");
                printf("Yakin ingin menghapus semua log error? (y/n): ");
                char confirm;
                scanf("%c", &confirm);
                getchar();
                if (confirm == 'y' || confirm == 'Y') {
                    ai_self_repair_clear_errors();
                    printf(GREEN "Log error berhasil dihapus.\n" RESET);
                } else {
                    printf(YELLOW "Dibatalkan.\n" RESET);
                }
                break;
                
            case 8: /* Simulate Error */
                printf(CYAN "\n=== SIMULATE ERROR ===" RESET "\n");
                printf("Kategori (MEMORY, IO, AI, SYSTEM): ");
                fgets(input, MAX_INPUT, stdin);
                input[strcspn(input, "\n")] = 0;
                printf("Pesan error: ");
                fgets(output, MAX_OUTPUT, stdin);
                output[strcspn(output, "\n")] = 0;
                ai_self_repair_simulate_error(input, output);
                printf(GREEN "Error simulasi berhasil dicatat.\n" RESET);
                break;
                
            default:
                printf(RED "Pilihan tidak valid!\n" RESET);
        }
        
        printf(YELLOW "\nTekan Enter untuk lanjut..." RESET);
        getchar();
    }
}

/* Main function */
int main(int argc, char *argv[]) {
    int choice;
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    
    /* Initialize AI system */
    ai_log_session_start();
    ai_persistence_load();
    ai_billing_init_session();
    
    /* Initialize Self-Repair system */
    ai_self_repair_init();
    
    /* Check for command-line mode */
    if (argc > 1) {
        if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
            printf("OS-Mini AI Command Line Usage:\n");
            printf("  %s                    - Interactive mode\n", argv[0]);
            printf("  %s \"message\"          - Direct input\n", argv[0]);
            printf("  %s --domain health    - Specify domain\n", argv[0]);
            return 0;
        }
        
        /* Direct message mode */
        if (argc >= 2) {
            char domain[32] = "";
            char *message = argv[1];
            
            if (argc >= 4 && strcmp(argv[1], "--domain") == 0) {
                strncpy(domain, argv[2], 31);
                message = argv[3];
            }
            
            ai_hub_request(domain, message, output);
            printf("%s\n", output);
            return 0;
        }
    }
    
    /* Interactive mode */
    print_banner();
    printf(GREEN "\nSelamat datang di OS-Mini AI Omega!\n" RESET);
    printf("Sistem telah dimuat dengan fitur:\n");
    printf("  ✅ Fuzzy Logic (Anti-typo)\n");
    printf("  ✅ Context-Aware Switching\n");
    printf("  ✅ Multi-language Detection\n");
    printf("  ✅ Sentiment Analysis\n");
    printf("  ✅ Long-term Memory\n");
    printf("  ✅ IoT Control\n");
    printf("  ✅ Self-Repair System\n\n");
    
    while (1) {
        print_menu();
        
        if (scanf("%d", &choice) != 1) {
            printf(RED "Error: Invalid input!\n" RESET);
            break;
        }
        getchar();
        
        switch(choice) {
            case 1:
                handle_health();
                break;
            case 2:
                handle_education();
                break;
            case 3:
                handle_finance();
                break;
            case 4:
                handle_manufacturing();
                break;
            case 5:
                handle_iot();
                break;
            case 6:
                handle_smartcity();
                break;
            case 7:
                handle_governance();
                break;
            case 8:
                handle_future();
                break;
            case 9:
                handle_codeagent();
                break;
            case 10:
                handle_destiny();
                break;
            case 11:
                handle_iot_status();
                break;
            case 12:
                handle_context_info();
                break;
            case 13:
                handle_self_repair();
                break;
            case 0:
                printf(GREEN "\nTerima kasih telah menggunakan OS-Mini AI!\n" RESET);
                printf(CYAN "Keep Learning, Keep Innovating! 🚀\n" RESET);
                ai_persistence_save();
                return 0;
            default:
                printf(RED "Pilihan tidak valid!\n" RESET);
        }
        
        printf(YELLOW "\nTekan Enter untuk lanjut..." RESET);
        getchar();
    }
    
    ai_persistence_save();
    return 0;
}

