/* ============================================================
   SECURITY MODULE - PIN Lock & Self-Destruct (ENHANCED)
   Provides authentication and system protection with improved input handling
   ============================================================ */
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include "../include/ai_hub.h"

#define DEFAULT_PIN "1234"
#define MAX_ATTEMPTS 3
#define LOCKOUT_TIME 300 /* 5 minutes in seconds */
#define MAX_PIN_LEN 16

static int failed_attempts = 0;
static time_t lockout_end_time = 0;

/* Disable echo for password input */
static void set_echo(int enable) {
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if (!enable) {
        tty.c_lflag &= ~ECHO;
    } else {
        tty.c_lflag |= ECHO;
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

/* Verify PIN - returns 1 if correct, 0 if wrong */
int ai_security_verify(void) {
    /* Check if system is locked out */
    time_t now = time(NULL);
    if (lockout_end_time > now) {
        int remaining = (int)(lockout_end_time - now);
        printf("\n!!! SYSTEM LOCKED !!!\n");
        printf("Too many failed attempts. Try again in %d seconds.\n", remaining);
        ai_log_blackbox("CRITICAL", "SECURITY", "System still locked out");
        return 0;
    }
    
    char pin[MAX_PIN_LEN];
    
    printf("\n=== SECURITY CHECK ===\n");
    printf("Enter PIN (default: 1234): ");
    
    /* Disable echo for PIN input */
    set_echo(0);
    
    if (fgets(pin, sizeof(pin), stdin) != NULL) {
        pin[strcspn(pin, "\n")] = 0;
    }
    
    /* Re-enable echo */
    set_echo(1);
    printf("\n");
    
    if (strcmp(pin, DEFAULT_PIN) == 0) {
        failed_attempts = 0;
        ai_log_blackbox("INFO", "SECURITY", "Access Granted");
        return 1;
    } else {
        failed_attempts++;
        char log_msg[128];
        snprintf(log_msg, sizeof(log_msg), "Failed login attempt #%d", failed_attempts);
        ai_log_blackbox("WARN", "SECURITY", log_msg);
        
        /* Check for self-destruct condition */
        if (failed_attempts >= MAX_ATTEMPTS) {
            ai_self_destruct_check(failed_attempts);
        }
        
        return 0;
    }
}

/* Self-destruct check - lockout after too many failed attempts */
void ai_self_destruct_check(int attempts) {
    if (attempts >= MAX_ATTEMPTS) {
        ai_log_blackbox("CRITICAL", "SECURITY", "Self-Destruct Sequence Initiated - Lockout");
        
        /* Set lockout time */
        lockout_end_time = time(NULL) + LOCKOUT_TIME;
        
        printf("\n!!! SECURITY ALERT !!!\n");
        printf("Too many failed attempts (%d).\n", attempts);
        printf("System locked for %d seconds.\n", LOCKOUT_TIME);
        
        failed_attempts = 0;
    }
}

