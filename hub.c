#include <string.h>
#include <stdio.h>
#include "ai_hub.h"

/* ============================================================
   OS-MINI AI HUB - Central AI Dispatcher
   Menghubungkan semua domain AI dari healthcare hingga destiny
   ============================================================ */

int ai_hub_request(const char *domain, const char *input, char *output) {
    if (strcmp(domain, "health") == 0) 
        return ai_health_analyze(input, output);
    else if (strcmp(domain, "edu") == 0) 
        return ai_edu_recommend(input, output);
    else if (strcmp(domain, "manufacture") == 0) 
        return ai_manufacture_predict(input, output);
    else if (strcmp(domain, "finance") == 0) 
        return ai_finance_analyze(input, output);
    else if (strcmp(domain, "iot") == 0) 
        return ai_iot_process("smart_home", input, output);
    else if (strcmp(domain, "smartcity") == 0) 
        return ai_transport_analyze(input, output);
    else if (strcmp(domain, "governance") == 0) 
        return ai_governance_check(input, output);
    else if (strcmp(domain, "quantum") == 0) 
        return ai_quantum_optimize(input, output);
    else if (strcmp(domain, "selflearn") == 0) 
        return ai_self_learn(input, "domain_default", output);
    else if (strcmp(domain, "adaptive") == 0) 
        return ai_adapt_context(input, output);
    else if (strcmp(domain, "community") == 0) 
        return ai_patch_submit("user", input);
    else if (strcmp(domain, "symbiosis") == 0) 
        return ai_symbiosis_collab(input, "context_default", output);
    else if (strcmp(domain, "transhuman") == 0) 
        return ai_bio_interface(input, output);
    else if (strcmp(domain, "cosmic") == 0) 
        return ai_cosmic_nav(input, output);
    else if (strcmp(domain, "singularity") == 0) 
        return ai_singularity_merge(input, output);
    else if (strcmp(domain, "infinity") == 0) 
        return ai_infinity_expand(input, output);
    else if (strcmp(domain, "metareality") == 0) 
        return ai_meta_integrate(input, output);
    else if (strcmp(domain, "destiny") == 0) 
        return ai_destiny_core(input, output);
    else {
        strcpy(output, "Domain AI tidak dikenali.");
        return -1;
    }
}
