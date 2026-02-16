/* ============================================================
   CODEAGENT - Complex Coding Task Handler
   Handles sophisticated programming tasks
   ============================================================ */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/ai_hub.h"

/* Analyze coding task and provide response */
int ai_codeagent_analyze(const char *task, char *response) {
    if (!task || !response) return -1;
    
    char lower_task[512];
    strncpy(lower_task, task, 511);
    lower_task[511] = '\0';
    
    for (int i = 0; lower_task[i]; i++) {
        lower_task[i] = (char)tolower(lower_task[i]);
    }
    
    if (strstr(lower_task, "algorithm")) {
        strcpy(response, "CodeAgent: Algoritma memerlukan analisis kompleksitas O(n log n). "
                "Rekomendasi: divide-and-conquer atau dynamic programming.");
    } else if (strstr(lower_task, "data structure")) {
        strcpy(response, "CodeAgent: Struktur data optimal adalah Hash Map untuk lookup O(1) "
                "atau B-Tree untuk sorted data.");
    } else if (strstr(lower_task, "performance")) {
        strcpy(response, "CodeAgent: Masalah performance terdeteksi. "
                "Saran: caching, minimalkan I/O blocking, pertimbangkan multi-threading.");
    } else if (strstr(lower_task, "security")) {
        strcpy(response, "CodeAgent: Potensi vulnerability ditemukan. "
                "Validasi input, gunakan prepared statements, implementasi rate limiting.");
    } else if (strstr(lower_task, "architecture")) {
        strcpy(response, "CodeAgent: Arsitektur yang direkomendasikan: "
                "Microservices, Event-Driven, atau Clean Architecture.");
    } else if (strstr(lower_task, "database")) {
        strcpy(response, "CodeAgent: Optimasi database diperlukan. "
                "Gunakan indexing, query optimization, pertimbangkan denormalization.");
    } else if (strstr(lower_task, "api")) {
        strcpy(response, "CodeAgent: Design API memerlukan RESTful principles, "
                "versioning, authentication (OAuth2/JWT), dan proper error handling.");
    } else if (strstr(lower_task, "testing")) {
        strcpy(response, "CodeAgent: Strategi testing: "
                "Unit tests (80%+ coverage), Integration tests, E2E dengan CI/CD.");
    } else {
        strcpy(response, "CodeAgent: Tugas coding dianalisis. "
                "Mohon detail lebih spesifik (algorithm, database, api, dll).");
    }
    return 0;
}

/* Generate code based on language and requirements */
int ai_codeagent_generate(const char *language, const char *requirements, char *code) {
    if (!language || !requirements || !code) return -1;
    
    char lang_lower[32];
    strncpy(lang_lower, language, 31);
    lang_lower[31] = '\0';
    
    for (int i = 0; lang_lower[i]; i++) {
        lang_lower[i] = (char)tolower(lang_lower[i]);
    }
    
    if (strcmp(lang_lower, "c") == 0 || strcmp(lang_lower, "cpp") == 0) {
        if (strstr(requirements, "linked list") || strstr(requirements, "list")) {
            strcpy(code, 
"/* Linked List Implementation in C */\n"
"#include <stdio.h>\n"
"#include <stdlib.h>\n\n"
"typedef struct Node {\n"
"    int data;\n"
"    struct Node* next;\n"
"} Node;\n\n"
"Node* createNode(int data) {\n"
"    Node* newNode = (Node*)malloc(sizeof(Node));\n"
"    newNode->data = data;\n"
"    newNode->next = NULL;\n"
"    return newNode;\n"
"}\n\n"
"void insertEnd(Node** head, int data) {\n"
"    Node* newNode = createNode(data);\n"
"    if (!*head) { *head = newNode; return; }\n"
"    Node* temp = *head;\n"
"    while (temp->next) temp = temp->next;\n"
"    temp->next = newNode;\n"
"}\n\n"
"void printList(Node* head) {\n"
"    while (head) { printf(\"%d -> \", head->data); head = head->next; }\n"
"    printf(\"NULL\\n\");\n"
"}\n\n"
"int main() {\n"
"    Node* head = NULL;\n"
"    insertEnd(&head, 1);\n"
"    insertEnd(&head, 2);\n"
"    printList(head);\n"
"    return 0;\n"
"}");
        } else if (strstr(requirements, "api server") || strstr(requirements, "server")) {
            strcpy(code,
"/* Simple HTTP API Server in C */\n"
"#include <stdio.h>\n"
"#include <stdlib.h>\n"
"#include <string.h>\n"
"#include <unistd.h>\n"
"#include <arpa/inet.h>\n\n"
"#define PORT 8080\n\n"
"void handleRequest(int clientSocket) {\n"
"    char buffer[1024] = {0};\n"
"    read(clientSocket, buffer, 1024);\n"
"    char* response = \"HTTP/1.1 200 OK\\r\\n\"\n"
"                     \"Content-Type: application/json\\r\\n\\n\"\n"
"                     {\\\"status\\\":\\\"ok\\\"}\";\n"
"    send(clientSocket, response, strlen(response), 0);\n"
"    close(clientSocket);\n"
"}\n\n"
"int main() {\n"
"    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);\n"
"    struct sockaddr_in address = {0};\n"
"    address.sin_family = AF_INET;\n"
"    address.sin_port = htons(PORT);\n"
"    address.sin_addr.s_addr = INADDR_ANY;\n"
"    \n"
"    bind(serverSocket, (struct sockaddr*)&address, sizeof(address));\n"
"    listen(serverSocket, 10);\n"
"    \n"
"    while (1) {\n"
"        int client = accept(serverSocket, NULL, NULL);\n"
"        handleRequest(client);\n"
"    }\n"
"    return 0;\n"
"}");
        } else {
            strcpy(code, "/* C code generation: specify linked list, api server, etc */");
        }
    } else if (strcmp(lang_lower, "python") == 0) {
        if (strstr(requirements, "web server") || strstr(requirements, "flask")) {
            strcpy(code,
"# Flask Web Server in Python\n"
"from flask import Flask, jsonify, request\n"
"\n"
"app = Flask(__name__)\n"
"\n"
"@app.route('/api/health', methods=['GET'])\n"
"def health_check():\n"
"    return jsonify({'status': 'healthy'}), 200\n"
"\n"
"@app.route('/api/data', methods=['GET', 'POST'])\n"
"def handle_data():\n"
"    if request.method == 'POST':\n"
"        return jsonify({'received': request.get_json()}), 201\n"
"    return jsonify({'data': []}), 200\n"
"\n"
"if __name__ == '__main__':\n"
"    app.run(host='0.0.0.0', port=5000)");
        } else if (strstr(requirements, "machine learning") || strstr(requirements, "ml")) {
            strcpy(code,
"# Machine Learning Pipeline in Python\n"
"import numpy as np\n"
"from sklearn.model_selection import train_test_split\n"
"from sklearn.ensemble import RandomForestClassifier\n"
"from sklearn.metrics import accuracy_score\n"
"\n"
"def train_model(X, y):\n"
"    X_train, X_test, y_train, y_test = train_test_split(\n"
"        X, y, test_size=0.2, random_state=42\n"
"    )\n"
"    model = RandomForestClassifier(n_estimators=100)\n"
"    model.fit(X_train, y_train)\n"
"    return model, accuracy_score(y_test, model.predict(X_test))\n"
"\n"
"# Usage: X, y = load_data(); model, acc = train_model(X, y)");
        } else {
            strcpy(code, "# Python: specify web server, machine learning, etc");
        }
    } else if (strcmp(lang_lower, "javascript") == 0 || strcmp(lang_lower, "js") == 0) {
        if (strstr(requirements, "async") || strstr(requirements, "api client")) {
            strcpy(code,
"// Async REST API Client in JavaScript\n"
"class APIClient {\n"
"    constructor(baseURL) { this.baseURL = baseURL; }\n"
"\n"
"    async get(endpoint) {\n"
"        const res = await fetch(`${this.baseURL}${endpoint}`);\n"
"        if (!res.ok) throw new Error(`HTTP ${res.status}`);\n"
"        return res.json();\n"
"    }\n"
"\n"
"    async post(endpoint, data) {\n"
"        return fetch(`${this.baseURL}${endpoint}`, {\n"
"            method: 'POST',\n"
"            headers: { 'Content-Type': 'application/json' },\n"
"            body: JSON.stringify(data)\n"
"        }).then(r => r.json());\n"
"    }\n"
"}\n"
"// Usage: const api = new APIClient('https://api.example.com');\n"
"// const data = await api.get('/users');");
        } else {
            strcpy(code, "// JavaScript: specify async, react, etc");
        }
    } else {
        sprintf(code, "/* Language '%s' not supported */", language);
    }
    return 0;
}

/* Debug code and provide fixes */
int ai_codeagent_debug(const char *code, const char *error, char *fix) {
    if (!error || !fix) return -1;
    
    char lower_error[256];
    strncpy(lower_error, error, 255);
    lower_error[255] = '\0';
    
    for (int i = 0; lower_error[i]; i++) {
        lower_error[i] = (char)tolower(lower_error[i]);
    }
    
    if (strstr(lower_error, "null pointer") || strstr(lower_error, "null reference") || strstr(lower_error, "null")) {
        strcpy(fix, "CodeAgent Debug: Null pointer error!\n"
                "Fix: Selalu periksa NULL sebelum dereferencing.\n"
                "Contoh: if (ptr != NULL) { /* use ptr */ }");
    } else if (strstr(lower_error, "segmentation fault") || strstr(lower_error, "segfault")) {
        strcpy(fix, "CodeAgent Debug: Segmentation fault!\n"
                "Kemungkinan: Akses memori di luar array, pointer tidak diinisialisasi, atau stack overflow.\n"
                "Fix: Gunakan gdb/valgrind untuk menemukan baris yang salah.");
    } else if (strstr(lower_error, "memory leak")) {
        strcpy(fix, "CodeAgent Debug: Memory leak!\n"
                "Fix: Setiap malloc() harus punya free().\n"
                "Gunakan: Valgrind --leak-check=full ./program");
    } else if (strstr(lower_error, "infinite loop")) {
        strcpy(fix, "CodeAgent Debug: Infinite loop!\n"
                "Fix: Pastikan kondisi terminasi akan terpenuhi.\n"
                "Periksa: Update variabel loop di dalam body.");
    } else if (strstr(lower_error, "race condition")) {
        strcpy(fix, "CodeAgent Debug: Race condition!\n"
                "Fix: Gunakan mutex/locks untuk resource bersama.\n"
                "Contoh: pthread_mutex_lock(&mutex);");
    } else if (strstr(lower_error, "sql injection")) {
        strcpy(fix, "CodeAgent Debug: SQL Injection vulnerability!\n"
                "CRITICAL: Gunakan parameterized queries/prepared statements.\n"
                "SALAH: query = \"SELECT * FROM users WHERE id = \" + userId\n"
                "BENAR: stmt = conn.prepare(\"SELECT * FROM users WHERE id = ?\")");
    } else if (strstr(lower_error, "deadlock")) {
        strcpy(fix, "CodeAgent Debug: Potential deadlock!\n"
                "Fix: Selalu ambil locks dalam urutan yang konsisten.\n"
                "Hindari: Nested locks atau circular wait.");
    } else {
        sprintf(fix, "CodeAgent Debug: Error '%s' dianalisis.\nBerikan pesan error spesifik untuk solusi detail.", error);
    }
    return 0;
}

/* Review code and provide feedback */
int ai_codeagent_review(const char *code, char *review) {
    if (!code || !review) return -1;
    
    if (strstr(code, "goto")) {
        strcpy(review, "CodeAgent Review: goto ditemukan!\n"
                "Rating: ⚠️ Warning\n"
                "Saran: Hindari goto, gunakan if/else atau loops.");
    } else if (strstr(code, "malloc") && !strstr(code, "free")) {
        strcpy(review, "CodeAgent Review: Memory allocation tanpa deallocation!\n"
                "Rating: 🔴 High Priority\n"
                "Issue: Potential memory leak - setiap malloc butuh free().");
    } else if (strstr(code, "eval(")) {
        strcpy(review, "CodeAgent Review: eval() terdeteksi!\n"
                "Rating: 🔴 Security Risk\n"
                "Saran: Hindari eval() - vulnerability security.");
    } else if (strstr(code, "SELECT") && strstr(code, "FROM") && !strstr(code, "WHERE")) {
        strcpy(review, "CodeAgent Review: SQL query tanpa WHERE!\n"
                "Rating: ⚠️ Warning\n"
                "Issue: Mengambil SEMUA records - masalah performa.");
    } else if (strstr(code, "async") && strstr(code, "await")) {
        strcpy(review, "CodeAgent Review: Async/await pattern!\n"
                "Rating: ✅ Good Practice\n"
                "Positif: Modern async pattern, non-blocking I/O.");
    } else {
        strcpy(review, "CodeAgent Review: Analisis selesai.\n"
                "Rating: ✅ Tidak ada issue kritis.\n"
                "Saran: Terus ikuti best practices.");
    }
    return 0;
}

/* Optimize code */
int ai_codeagent_optimize(const char *code, char *optimized) {
    if (!code || !optimized) return -1;
    
    if (strstr(code, "SELECT *")) {
        strcpy(optimized, "CodeAgent Optimization: SQL query!\n\n"
                "Before: SELECT * FROM table\n"
                "After: SELECT column1, column2 FROM table\n\n"
                "Benefit: Mengurangi transfer data, improve performance.");
    } else if (strstr(code, "String") && strstr(code, "+") && !strstr(code, "StringBuilder")) {
        strcpy(optimized, "CodeAgent Optimization: String concatenation!\n\n"
                "Before: str = str + \"new\";\n"
                "After: StringBuilder.append(\"new\");\n\n"
                "Benefit: O(n) instead of O(n²).");
    } else if (strstr(code, "==") && strstr(code, "String")) {
        strcpy(optimized, "CodeAgent Optimization: String comparison!\n\n"
                "Before: str1 == str2 (compares references)\n"
                "After: str1.equals(str2)\n\n"
                "Benefit: Proper content comparison, avoids NPE.");
    } else {
        strcpy(optimized, "CodeAgent Optimization: Rekomendasi umum:\n\n"
                "1. Profile dulu sebelum optimize\n"
                "2. Gunakan data structures yang tepat\n"
                "3. Minimalkan I/O, batch jika memungkinkan\n"
                "4. Pertimbangkan caching untuk data sering akses\n"
                "5. Lazy initialization dimana tepat");
    }
    return 0;
}

/* Explain code */
int ai_codeagent_explain(const char *code, char *explanation) {
    if (!code || !explanation) return -1;
    
    char lower_code[256];
    strncpy(lower_code, code, 255);
    lower_code[255] = '\0';
    
    for (int i = 0; lower_code[i]; i++) {
        lower_code[i] = (char)tolower(lower_code[i]);
    }
    
    if (strstr(lower_code, "typedef struct") || strstr(lower_code, "struct")) {
        strcpy(explanation, "CodeAgent: Data Structure Definition\n\n"
                "Kode ini mendefinisikan custom data structure (struct).\n"
                "- typedef membuat shortcut untuk struct\n"
                "- Struct mengelompokkan different data types\n"
                "- Gunakan untuk: records, linked nodes, game objects, dll.");
    } else if (strstr(lower_code, "pthread") || strstr(lower_code, "thread")) {
        strcpy(explanation, "CodeAgent: Multi-threading\n\n"
                "Kode ini menggunakan threads untuk concurrent execution.\n"
                "- Multiple threads berbagi memory space yang sama\n"
                "- Synchronization (mutex) dibutuhkan untuk shared data\n"
                "- Benefits: CPU utilization lebih baik, responsive UI\n"
                "- Risks: Race conditions, deadlocks");
    } else if (strstr(lower_code, "select") && strstr(lower_code, "from")) {
        strcpy(explanation, "CodeAgent: SQL Database Query\n\n"
                "Ini adalah perintah database query language:\n"
                "- SELECT: Specifies columns untuk retrieve\n"
                "- FROM: Specifies table(s) untuk query\n"
                "- WHERE: Filters results (optional)\n"
                "- JOIN: Combines related tables");
    } else if (strstr(lower_code, "def ") || strstr(lower_code, "function")) {
        strcpy(explanation, "CodeAgent: Function/Method Definition\n\n"
                "Ini mendefinisikan reusable block of code:\n"
                "- Parameters: Input values yang diterima function\n"
                "- Return type: Tipe nilai yang dikembalikan\n"
                "- Body: Actual code logic\n"
                "- Best practice: Single responsibility, clear naming.");
    } else if (strstr(lower_code, "class ")) {
        strcpy(explanation, "CodeAgent: Object-Oriented Class\n\n"
                "Ini mendefinisikan blueprint untuk objects:\n"
                "- Fields/Properties: Data yang dihold object\n"
                "- Methods: Functions yang bisa dilakukan object\n"
                "- Constructors: Initialize object state\n"
                "- Encapsulation: Hide internal details");
    } else if (strstr(lower_code, "async") || strstr(lower_code, "await")) {
        strcpy(explanation, "CodeAgent: Asynchronous Programming\n\n"
                "Kode ini menggunakan async/await pattern:\n"
                "- async: Menandai function sebagai asynchronous\n"
                "- await: Jeda execution sampai promise resolve\n"
                "- Non-blocking: Kode lain bisa jalan sementara menunggu\n"
                "- Common use: API calls, file I/O, database queries");
    } else {
        strcpy(explanation, "CodeAgent: Kode ini sepertinya mengimplementasikan konsep pemrograman.\n"
                "Untuk penjelasan detail, berikan:\n"
                "- Bahasa pemrograman spesifik\n"
                "- Konteks/tujuan kode\n"
                "- Bagian spesifik yang ingin dijelaskan");
    }
    return 0;
}
