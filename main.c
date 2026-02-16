/* ============================================================
   OS-MINI AI - Main Entry Point
   Enhanced with Context-Aware Intelligence & Self-Repair
   ============================================================ */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "../include/ai_hub.h"

#define MAX_INPUT 4096
#define MAX_OUTPUT 8192

/* Color codes for terminal output */
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

/* Print banner */
void print_banner() {
    printf(BOLD CYAN);
    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║           OS-MINI AI OMEGA v1.0.0                         ║\n");
    printf("║           Multi-Domain Intelligence System                  ║\n");
    printf("║           Powered by CodeAgent & Self-Repair             ║\n");
    printf("╚═══════════════════════════════════════════════════════════════╝\n");
    printf(RESET);
}

/* Print main menu */
void print_menu() {
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
    printf(GREEN "  [13]" RESET " Self-Repair    - Auto fix bug & health check\n");
    printf(BOLD RED "  [0]" RESET " Exit\n");
    printf(YELLOW "\n>>> Pilih menu: " RESET);
}

/* Print CodeAgent menu */
void print_codeagent_menu() {
    printf(BOLD MAGENTA "\n═══ CODEAGENT - COMPLEX CODING HANDLER ===" RESET "\n");
    printf(BLUE "  [1]" RESET " Analyze Task      - Analisis tugas coding kompleks\n");
    printf(BLUE "  [2]" RESET " Generate Code     - Generate kode (C, Python, JS, etc)\n");
    printf(BLUE "  [3]" RESET " Debug & Fix       - Debug error & berikan solusi\n");
    printf(BLUE "  [4]" RESET " Code Review       - Review kode, temukan issue\n");
    printf(BLUE "  [5]" RESET " Optimize          - Optimasi performa kode\n");
    printf(BLUE "  [6]" RESET " Explain           - Jelaskan kode secara detail\n");
    printf(BOLD RED "  [0]" RESET " Back to main menu\n");
    printf(YELLOW "\n>>> Pilih menu: " RESET);
}

/* Handle Healthcare AI */
void handle_health() {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    
    printf(CYAN "\n=== HEALTHCARE AI ===" RESET "\n");
    printf("Masukkan gejala (例: batuk, demam, sakit kepala, sesak, mual): ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;
    
    ai_health_analyze(input, output);
    printf(GREEN "\n📋 Diagnosis: %s\n" RESET, output);
}

/* Handle Education AI */
void handle_education() {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    
    printf(CYAN "\n=== EDUCATION AI ===" RESET "\n");
    printf("Masukkan topik (例: matematika, sejarah, fisika, bahasa, programming): ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;
    
    ai_edu_recommend(input, output);
    printf(GREEN "\n📚 Materi: %s\n" RESET, output);
}

/* Handle Finance AI */
void handle_finance() {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    
    printf(CYAN "\n=== FINANCE AI ===" RESET "\n");
    printf("Masukkan transaksi (例: jumlah besar, investasi, regular, foreign, crypto): ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;
    
    ai_finance_analyze(input, output);
    printf(GREEN "\n💰 Analisis: %s\n" RESET, output);
}

/* Handle Manufacturing AI */
void handle_manufacturing() {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    
    printf(CYAN "\n=== MANUFACTURING AI ===" RESET "\n");
    printf("Masukkan data sensor (例: vibration_high, temp_high, pressure_drop, oil_low): ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;
    
    ai_manufacture_predict(input, output);
    printf(GREEN "\n🏭 Laporan: %s\n" RESET, output);
}

/* Handle IoT AI */
void handle_iot() {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    
    printf(CYAN "\n=== IoT AI ===" RESET "\n");
    printf("Masukkan perintah (例: lamp_on, ac_temp_high, overheat, status): ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;
    
    ai_iot_process("smart_home", input, output);
    printf(GREEN "\n🏠 Status: %s\n" RESET, output);
}

/* Handle Smart City AI */
void handle_smartcity() {
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
    getchar(); // consume newline
    
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
            printf("Data lingkungan (例: polusi, hujan, temp_anomaly, quality_good): ");
            fgets(input, MAX_INPUT, stdin);
            input[strcspn(input, "\n")] = 0;
            ai_env_analyze(input, output);
            printf(GREEN "\n🌍 Hasil: %s\n" RESET, output);
            break;
        case 4:
            printf("Permintaan layanan (例: ambulance, pemadam, polisi, maintenance): ");
            fgets(input, MAX_INPUT, stdin);
            input[strcspn(input, "\n")] = 0;
            ai_service_request(input, output);
            printf(GREEN "\n🚑 Respons: %s\n" RESET, output);
            break;
        default:
            printf(RED "Pilihan tidak valid!\n" RESET);
    }
}

/* Handle Governance AI */
void handle_governance() {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    
    printf(CYAN "\n=== GOVERNANCE AI ===" RESET "\n");
    printf("Masukkan kebijakan (例: privacy, security, finance, labor): ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;
    
    ai_governance_check(input, output);
    printf(GREEN "\n⚖️ Compliance: %s\n" RESET, output);
}

/* Handle Future AI */
void handle_future() {
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
    getchar(); // consume newline
    
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
            ai_self_learn(input, "domain_default", output);
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

/* Handle CodeAgent - Complex Coding Tasks */
void handle_codeagent() {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    char code_input[MAX_INPUT * 4];
    int submenu;
    
    while (1) {
        print_codeagent_menu();
        scanf("%d", &submenu);
        getchar(); // consume newline
        
        if (submenu == 0) break;
        
        switch(submenu) {
            case 1: // Analyze
                printf(CYAN "\n=== CODEAGENT ANALYZE ===" RESET "\n");
                printf("Masukkan tugas coding (algorithm, data structure, performance, security, architecture, database, api, testing): ");
                fgets(input, MAX_INPUT, stdin);
                input[strcspn(input, "\n")] = 0;
                ai_codeagent_analyze(input, output);
                printf(GREEN "\n📊 Analysis:\n%s\n" RESET, output);
                break;
                
            case 2: // Generate
                printf(CYAN "\n=== CODEAGENT CODE GENERATION ===" RESET "\n");
                printf("Pilih bahasa: [1] C [2] Python [3] JavaScript: ");
                int lang_choice;
                scanf("%d", &lang_choice);
                getchar();
                
                char language[32];
                if (lang_choice == 1) strcpy(language, "c");
                else if (lang_choice == 2) strcpy(language, "python");
                else if (lang_choice == 3) strcpy(language, "javascript");
                else { printf(RED "Pilihan tidak valid!\n" RESET); break; }
                
                printf("Requirements (linked list, api server, web server, machine learning, async): ");
                fgets(input, MAX_INPUT, stdin);
                input[strcspn(input, "\n")] = 0;
                
                ai_codeagent_generate(language, input, output);
                printf(GREEN "\n💻 Generated Code:\n\n%s\n" RESET, output);
                break;
                
            case 3: // Debug
                printf(CYAN "\n=== CODEAGENT DEBUG ===" RESET "\n");
                printf("Masukkan deskripsi error (null pointer, segmentation fault, memory leak, infinite loop, race condition, sql injection, deadlock): ");
                fgets(input, MAX_INPUT, stdin);
                input[strcspn(input, "\n")] = 0;
                
                ai_codeagent_debug("", input, output);
                printf(GREEN "\n🔧 Debug & Fix:\n%s\n" RESET, output);
                break;
                
            case 4: // Review
                printf(CYAN "\n=== CODEAGENT CODE REVIEW ===" RESET "\n");
                printf("Masukkan kode untuk direview (atau keyword: goto, malloc, eval, SELECT, printf): ");
                fgets(code_input, MAX_INPUT * 4, stdin);
                code_input[strcspn(code_input, "\n")] = 0;
                
                ai_codeagent_review(code_input, output);
                printf(GREEN "\n📝 Code Review:\n%s\n" RESET, output);
                break;
                
            case 5: // Optimize
                printf(CYAN "\n=== CODEAGENT OPTIMIZE ===" RESET "\n");
                printf("Masukkan kode atau pattern (ArrayList, SELECT *, String+, == String): ");
                fgets(code_input, MAX_INPUT * 4, stdin);
                code_input[strcspn(code_input, "\n")] = 0;
                
                ai_codeagent_optimize(code_input, output);
                printf(GREEN "\n⚡ Optimization:\n%s\n" RESET, output);
                break;
                
            case 6: // Explain
                printf(CYAN "\n=== CODEAGENT EXPLAIN ===" RESET "\n");
                printf("Masukkan kode untuk dijelaskan (struct, pthread, SELECT, def, class, async): ");
                fgets(code_input, MAX_INPUT * 4, stdin);
                code_input[strcspn(code_input, "\n")] = 0;
                
                ai_codeagent_explain(code_input, output);
                printf(GREEN "\n📖 Explanation:\n%s\n" RESET, output);
                break;
                
            default:
                printf(RED "Pilihan tidak valid!\n" RESET);
        }
        
        printf(YELLOW "\nTekan Enter untuk lanjut..." RESET);
        getchar();
    }
}

/* Handle Destiny */
void handle_destiny() {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    
    printf(CYAN "\n=== DESTINY AI ===" RESET "\n");
    printf("Masukkan pertanyaan tentang masa depan: ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;
    
    ai_destiny_core(input, output);
    printf(GREEN "\n✨ Destiny: %s\n" RESET, output);
}

/* Handle IoT Status */
void handle_iot_status() {
    char output[MAX_OUTPUT];
    
    printf(CYAN "\n=== IoT DEVICE STATUS ===" RESET "\n");
    strcpy(output, ai_iot_get_status());
    printf(GREEN "%s\n" RESET, output);
}

/* Handle Context Info */
void handle_context_info() {
    char lang[32] = "Unknown";
    char emotion[32] = "Neutral";
    char prediction[128] = "Waiting...";
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
void handle_self_repair() {
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
                
            /* Run Diagnostics */
 case 2:                printf(CYAN "\n=== RUNNING DIAGNOSTICS ===" RESET "\n");
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
            printf("  %s --health \"demam\"  - Health AI\n", argv[0]);
            printf("  %s --edu \"math\"      - Education AI\n", argv[0]);
            printf("  %s --codeagent \"algorithm\" - CodeAgent\n", argv[0]);
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
        getchar(); // consume newline
        
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

