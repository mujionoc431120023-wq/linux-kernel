#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* ============================================================
   CODEAGENT - Complex Coding Task Handler
   Handles sophisticated programming tasks including:
   - Code analysis
   - Code generation
   - Bug debugging
   - Code review
   - Optimization
   - Explanation
   ============================================================ */

/* Analyze coding task and provide response */
int ai_codeagent_analyze(const char *task, char *response) {
    if (strstr(task, "algorithm")) {
        strcpy(response, "CodeAgent: Algoritma yang diminta memerlukan analisis kompleksitas O(n log n). ");
        strcat(response, "Rekomendasi: gunakan divide-and-conquer atau dynamic programming.");
    } else if (strstr(task, "data structure")) {
        strcpy(response, "CodeAgent: Struktur data optimal untuk kasus ini adalah ");
        strcat(response, "Hash Map untuk lookup O(1) atau B-Tree untuk sorted data.");
    } else if (strstr(task, "performance")) {
        strcpy(response, "CodeAgent: Masalah performance terdeteksi. ");
        strcat(response, "Saran: Gunakan caching, minimalkan I/O blocking, pertimbangkan multi-threading.");
    } else if (strstr(task, "security")) {
        strcpy(response, "CodeAgent: Analisis security menemukan potensi vulnerability. ");
        strcat(response, "Validasi input, gunakan prepared statements, implementasi rate limiting.");
    } else if (strstr(task, "architecture")) {
        strcpy(response, "CodeAgent: Untuk arsitektur yang diminta, pertimbangkan pattern: ");
        strcat(response, "Microservices, Event-Driven, atau Clean Architecture.");
    } else if (strstr(task, "database")) {
        strcpy(response, "CodeAgent: Optimasi database diperlukan. ");
        strcat(response, "Gunakan indexing, query optimization, pertimbangkan denormalization.");
    } else if (strstr(task, "api")) {
        strcpy(response, "CodeAgent: Design API yang baik memerlukan RESTful principles, ");
        strcat(response, "versioning, authentication (OAuth2/JWT), dan proper error handling.");
    } else if (strstr(task, "testing")) {
        strcpy(response, "CodeAgent: Strategi testing yang direkomendasikan: ");
        strcat(response, "Unit tests (80%+ coverage), Integration tests, E2E tests dengan CI/CD.");
    } else {
        strcpy(response, "CodeAgent: Tugas coding dianalisis. ");
        strcat(response, "Mohon berikan detail lebih spesifik (algorithm, database, api, etc).");
    }
    return 0;
}

/* Generate code based on language and requirements */
int ai_codeagent_generate(const char *language, const char *requirements, char *code) {
    char template[4096];
    
    if (strcmp(language, "c") == 0 || strcmp(language, "C") == 0) {
        if (strstr(requirements, "linked list")) {
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
"void insertAtEnd(Node** head, int data) {\n"
"    Node* newNode = createNode(data);\n"
"    if (*head == NULL) {\n"
"        *head = newNode;\n"
"        return;\n"
"    }\n"
"    Node* temp = *head;\n"
"    while (temp->next != NULL) temp = temp->next;\n"
"    temp->next = newNode;\n"
"}\n\n"
"void printList(Node* head) {\n"
"    while (head != NULL) {\n"
"        printf(\"%d -> \", head->data);\n"
"        head = head->next;\n"
"    }\n"
"    printf(\"NULL\\n\");\n"
"}");
        } else if (strstr(requirements, "api server")) {
            strcpy(code,
"/* Simple HTTP API Server in C */\n"
"#include <stdio.h>\n"
"#include <stdlib.h>\n"
"#include <string.h>\n"
"#include <unistd.h>\n"
"#include <arpa/inet.h>\n\n"
"#define PORT 8080\n"
"#define BUFFER_SIZE 4096\n\n"
"void handleRequest(int clientSocket) {\n"
"    char buffer[BUFFER_SIZE] = {0};\n"
"    read(clientSocket, buffer, BUFFER_SIZE);\n"
"    \n"
"    char* response = \"HTTP/1.1 200 OK\\r\\n\"\n"
"                     \"Content-Type: application/json\\r\\n\\n\"\n"
"                     {\\\"status\\\":\\\"ok\\\"}\";\n"
"    send(clientSocket, response, strlen(response), 0);\n"
"    close(clientSocket);\n"
"}\n\n"
"int main() {\n"
"    int serverSocket, clientSocket;\n"
"    struct sockaddr_in address;\n"
"    int opt = 1;\n"
"    \n"
"    serverSocket = socket(AF_INET, SOCK_STREAM, 0);\n"
"    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));\n"
"    \n"
"    address.sin_family = AF_INET;\n"
"    address.sin_addr.s_addr = INADDR_ANY;\n"
"    address.sin_port = htons(PORT);\n"
"    \n"
"    bind(serverSocket, (struct sockaddr*)&address, sizeof(address));\n"
"    listen(serverSocket, 10);\n"
"    \n"
"    while (1) {\n"
"        clientSocket = accept(serverSocket, NULL, NULL);\n"
"        handleRequest(clientSocket);\n"
"    }\n"
"    return 0;\n"
"}");
        } else {
            strcpy(code, "/* C code generation: specify linked list, api server, etc */");
        }
    } else if (strcmp(language, "python") == 0 || strcmp(language, "Python") == 0) {
        if (strstr(requirements, "web server")) {
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
"        data = request.get_json()\n"
"        return jsonify({'received': data}), 201\n"
"    return jsonify({'data': []}), 200\n"
"\n"
"if __name__ == '__main__':\n"
"    app.run(host='0.0.0.0', port=5000, debug=True)");
        } else if (strstr(requirements, "machine learning")) {
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
"    \n"
"    model = RandomForestClassifier(n_estimators=100, random_state=42)\n"
"    model.fit(X_train, y_train)\n"
"    \n"
"    predictions = model.predict(X_test)\n"
"    accuracy = accuracy_score(y_test, predictions)\n"
"    \n"
"    return model, accuracy\n"
"\n"
"# Usage:\n"
"# X = np.array([[1, 2], [3, 4], [5, 6]])\n"
"# y = np.array([0, 1, 0])\n"
"# model, acc = train_model(X, y)\n"
"# print(f'Accuracy: {acc}')");
        } else {
            strcpy(code, "# Python code generation: specify web server, machine learning, etc");
        }
    } else if (strcmp(language, "javascript") == 0 || strcmp(language, "js") == 0) {
        if (strstr(requirements, "async")) {
            strcpy(code,
"// Async/Await REST API Client in JavaScript\n"
"class APIClient {\n"
"    constructor(baseURL) {\n"
"        this.baseURL = baseURL;\n"
"    }\n"
"\n"
"    async get(endpoint) {\n"
"        const response = await fetch(`${this.baseURL}${endpoint}`);\n"
"        if (!response.ok) throw new Error(`HTTP ${response.status}`);\n"
"        return response.json();\n"
"    }\n"
"\n"
"    async post(endpoint, data) {\n"
"        const response = await fetch(`${this.baseURL}${endpoint}`, {\n"
"            method: 'POST',\n"
"            headers: { 'Content-Type': 'application/json' },\n"
"            body: JSON.stringify(data)\n"
"        });\n"
"        if (!response.ok) throw new Error(`HTTP ${response.status}`);\n"
"        return response.json();\n"
"    }\n"
"\n"
"    async put(endpoint, data) {\n"
"        const response = await fetch(`${this.baseURL}${endpoint}`, {\n"
"            method: 'PUT',\n"
"            headers: { 'Content-Type': 'application/json' },\n"
"            body: JSON.stringify(data)\n"
"        });\n"
"        if (!response.ok) throw new Error(`HTTP ${response.status}`);\n"
"        return response.json();\n"
"    }\n"
"}\n"
"\n"
"// Usage:\n"
"// const api = new APIClient('https://api.example.com');\n"
"// const data = await api.get('/users');");
        } else {
            strcpy(code, "// JavaScript code generation: specify async, react component, etc");
        }
    } else {
        sprintf(code, "/* CodeAgent: Language '%s' not fully supported yet. */", language);
    }
    return 0;
}

/* Debug code and provide fixes */
int ai_codeagent_debug(const char *code, const char *error, char *fix) {
    if (strstr(error, "null pointer") || strstr(error, "null reference")) {
        strcpy(fix, "CodeAgent Debug: Null pointer error detected!\n");
        strcat(fix, "Fix: Always check for NULL before dereferencing.\n");
        strcat(fix, "Example: if (ptr != NULL) { // use ptr }");
    } else if (strstr(error, "segmentation fault") || strstr(error, "segfault")) {
        strcpy(fix, "CodeAgent Debug: Segmentation fault detected!\n");
        strcat(fix, "Possible causes:\n");
        strcat(fix, "1. Accessing memory outside array bounds\n");
        strcat(fix, "2. Using uninitialized pointers\n");
        strcat(fix, "3. Stack overflow from recursion\n");
        strcat(fix, "Fix: Use debugging tools (gdb, valgrind) to find exact line.");
    } else if (strstr(error, "memory leak")) {
        strcpy(fix, "CodeAgent Debug: Memory leak detected!\n");
        strcat(fix, "Fix: Ensure every malloc() has corresponding free().\n");
        strcat(fix, "Use: Valgrind --leak-check=full ./program");
    } else if (strstr(error, "infinite loop")) {
        strcpy(fix, "CodeAgent Debug: Infinite loop detected!\n");
        strcat(fix, "Fix: Ensure loop termination condition will be met.\n");
        strcat(fix, "Check: Update loop variable inside the loop body.");
    } else if (strstr(error, "race condition")) {
        strcpy(fix, "CodeAgent Debug: Race condition detected!\n");
        strcat(fix, "Fix: Use mutex/locks for shared resources.\n");
        strcat(fix, "Example: pthread_mutex_lock(&mutex) before accessing shared data.");
    } else if (strstr(error, "sql injection")) {
        strcpy(fix, "CodeAgent Debug: SQL Injection vulnerability!\n");
        strcat(fix, "CRITICAL: Use parameterized queries/prepared statements.\n");
        strcat(fix, "WRONG:  query = \"SELECT * FROM users WHERE id = \" + userId\n");
        strcat(fix, "RIGHT:  stmt = conn.prepare(\"SELECT * FROM users WHERE id = ?\")");
    } else if (strstr(error, "deadlock")) {
        strcpy(fix, "CodeAgent Debug: Potential deadlock detected!\n");
        strcat(fix, "Fix: Always acquire locks in consistent order.\n");
        strcat(fix, "Avoid: Nested locks or circular wait dependencies.");
    } else {
        sprintf(fix, "CodeAgent Debug: Error '%s' analyzed.\nProvide more specific error message for detailed fix.", error);
    }
    return 0;
}

/* Review code and provide feedback */
int ai_codeagent_review(const char *code, char *review) {
    if (strstr(code, "goto")) {
        strcpy(review, "CodeAgent Review: goto statement found!\n");
        strcat(review, "Rating: ⚠️ Warning\n");
        strcat(review, "Advice: Avoid goto, use structured control flow (if/else, loops).\n");
        strcat(review, "goto makes code hard to maintain and understand.");
    } else if (strstr(code, "malloc") && !strstr(code, "free")) {
        strcpy(review, "CodeAgent Review: Memory allocation without deallocation!\n");
        strcat(review, "Rating: 🔴 High Priority\n");
        strcat(review, "Issue: Potential memory leak - every malloc needs free.\n");
        strcat(review, "Fix: Add free() in error paths and function end.");
    } else if (strstr(code, "eval(")) {
        strcpy(review, "CodeAgent Review: eval() usage detected!\n");
        strcat(review, "Rating: 🔴 Security Risk\n");
        strcat(review, "Advice: Avoid eval() - major security vulnerability.\n");
        strcat(review, "Use: JSON.parse() or structured data parsing instead.");
    } else if (strstr(code, "SELECT") && strstr(code, "FROM") && !strstr(code, "WHERE")) {
        strcpy(review, "CodeAgent Review: SQL query without WHERE clause!\n");
        strcat(review, "Rating: ⚠️ Warning\n");
        strcat(review, "Issue: This will fetch ALL records - performance issue.\n");
        strcat(review, "Fix: Add WHERE clause to filter results.");
    } else if (strstr(code, "sudo")) {
        strcpy(review, "CodeAgent Review: sudo usage in script!\n");
        strcat(review, "Rating: ⚠️ Security Consideration\n");
        strcat(review, "Advice: Minimize privilege escalation.\n");
        strcat(review, "Use specific sudoers configuration for commands.");
    } else if (strstr(code, "printf") && strstr(code, "%s") && !strstr(code, "sanitize")) {
        strcpy(review, "CodeAgent Review: Potential format string vulnerability!\n");
        strcat(review, "Rating: ⚠️ Warning\n");
        strcat(review, "Issue: User input in printf can be exploited.\n");
        strcat(review, "Fix: Use printf(\"%s\", user_input) instead of printf(user_input).");
    } else if (strstr(code, "async") && strstr(code, "await")) {
        strcpy(review, "CodeAgent Review: Async/await pattern detected!\n");
        strcat(review, "Rating: ✅ Good Practice\n");
        strcat(review, "Positive: Modern async pattern, non-blocking I/O.\n");
        strcat(review, "Advice: Add proper error handling with try/catch.");
    } else if (strstr(code, "// TODO") || strstr(code, "// FIXME")) {
        strcpy(review, "CodeAgent Review: TODO/FIXME comments found!\n");
        strcat(review, "Rating: ℹ️ Info\n");
        strcat(review, "Action: Complete these items before production release.");
    } else {
        strcpy(review, "CodeAgent Review: Code analysis complete.\n");
        strcat(review, "Rating: ✅ No critical issues detected.\n");
        strcat(review, "Advice: Continue following best practices.");
    }
    return 0;
}

/* Optimize code */
int ai_codeagent_optimize(const char *code, char *optimized) {
    if (strstr(code, "for") && strstr(code, "ArrayList") && strstr(code, ".add")) {
        strcpy(optimized, "CodeAgent Optimization: Array operations detected!\n\n");
        strcat(optimized, "Before: Repeated array resizing\n");
        strcat(optimized, "After: Use initial capacity or ArrayDeque\n\n");
        strcat(optimized, "Example: new ArrayList<>(initialCapacity)");
    } else if (strstr(code, "SELECT *")) {
        strcpy(optimized, "CodeAgent Optimization: SQL query detected!\n\n");
        strcat(optimized, "Before: SELECT * FROM table\n");
        strcat(optimized, "After: SELECT column1, column2 FROM table\n\n");
        strcat(optimized, "Benefit: Reduces data transfer, improves performance.");
    } else if (strstr(code, "while") && strstr(code, "true")) {
        strcpy(optimized, "CodeAgent Optimization: Infinite loop pattern!\n\n");
        strcat(optimized, "Advice: Use for-loops when iteration count is known.\n");
        strcat(optimized, "Consider: Breaking condition and performance implications.");
    } else if (strstr(code, "String") && strstr(code, "+")) {
        strcpy(optimized, "CodeAgent Optimization: String concatenation detected!\n\n");
        strcat(optimized, "Before: str = str + \"new\";\n");
        strcat(optimized, "After: StringBuilder.append(\"new\");\n\n");
        strcat(optimized, "Benefit: O(n) instead of O(n²) for multiple concatenations.");
    } else if (strstr(code, "==") && strstr(code, "String")) {
        strcpy(optimized, "CodeAgent Optimization: String comparison detected!\n\n");
        strcat(optimized, "Before: str1 == str2 (compares references)\n");
        strcat(optimized, "After: str1.equals(str2) or Objects.equals()\n\n");
        strcat(optimized, "Benefit: Proper content comparison, avoids NPE.");
    } else {
        strcpy(optimized, "CodeAgent Optimization: General recommendations:\n\n");
        strcat(optimized, "1. Profile first before optimizing\n");
        strcat(optimized, "2. Use appropriate data structures\n");
        strcat(optimized, "3. Minimize I/O operations, batch when possible\n");
        strcat(optimized, "4. Consider caching frequently accessed data\n");
        strcat(optimized, "5. Use lazy initialization where appropriate");
    }
    return 0;
}

/* Explain code */
int ai_codeagent_explain(const char *code, char *explanation) {
    if (strstr(code, "typedef struct") || strstr(code, "struct")) {
        strcpy(explanation, "CodeAgent Explanation: Data Structure Definition\n\n");
        strcat(explanation, "This code defines a custom data structure (struct).\n");
        strcat(explanation, "- 'typedef' creates a shortcut name for the struct\n");
        strcat(explanation, "- Struct groups different data types together\n");
        strcat(explanation, "- Used for: records, linked nodes, game objects, etc.\n\n");
        strcat(explanation, "Example use case: Creating a linked list node with data and pointer.");
    } else if (strstr(code, "pthread") || strstr(code, "thread")) {
        strcpy(explanation, "CodeAgent Explanation: Multi-threading\n\n");
        strcat(explanation, "This code uses threads for concurrent execution.\n");
        strcat(explanation, "- Multiple threads share same memory space\n");
        strcat(explanation, "- Synchronization (mutex) needed for shared data\n");
        strcat(explanation, "- Benefits: Better CPU utilization, responsive UI\n");
        strcat(explanation, "- Risks: Race conditions, deadlocks\n\n");
        strcat(explanation, "Best practice: Minimize shared state between threads.");
    } else if (strstr(code, "SELECT") && strstr(code, "FROM")) {
        strcpy(explanation, "CodeAgent Explanation: SQL Database Query\n\n");
        strcat(explanation, "This is a database query language command:\n");
        strcat(explanation, "- SELECT: Specifies columns to retrieve\n");
        strcat(explanation, "- FROM: Specifies table(s) to query\n");
        strcat(explanation, "- WHERE: Filters results (optional)\n");
        strcat(explanation, "- JOIN: Combines related tables\n\n");
        strcat(explanation, "Best practice: Use parameterized queries to prevent SQL injection.");
    } else if (strstr(code, "def ") || strstr(code, "function")) {
        strcpy(explanation, "CodeAgent Explanation: Function/Method Definition\n\n");
        strcat(explanation, "This defines a reusable block of code:\n");
        strcat(explanation, "- Parameters: Input values the function accepts\n");
        strcat(explanation, "- Return type: Type of value returned (if any)\n");
        strcat(explanation, "- Body: The actual code logic\n\n");
        strcat(explanation, "Best practice: Single responsibility, clear naming, document intent.");
    } else if (strstr(code, "class ")) {
        strcpy(explanation, "CodeAgent Explanation: Object-Oriented Class\n\n");
        strcat(explanation, "This defines a blueprint for objects:\n");
        strcat(explanation, "- Fields/Properties: Data the object holds\n");
        strcat(explanation, "- Methods: Functions the object can perform\n");
        strcat(explanation, "- Constructors: Initialize object state\n");
        strcat(explanation, "- Encapsulation: Hide internal details\n\n");
        strcat(explanation, "Key OOP principles: Inheritance, Polymorphism, Encapsulation.");
    } else if (strstr(code, "async") || strstr(code, "await")) {
        strcpy(explanation, "CodeAgent Explanation: Asynchronous Programming\n\n");
        strcat(explanation, "This code uses async/await pattern:\n");
        strcat(explanation, "- async: Marks function as asynchronous\n");
        strcat(explanation, "- await: Pauses execution until promise resolves\n");
        strcat(explanation, "- Non-blocking: Other code can run while waiting\n");
        strcat(explanation, "- Common use: API calls, file I/O, database queries\n\n");
        strcat(explanation, "Benefits: Better performance, more responsive applications.");
    } else {
        strcpy(explanation, "CodeAgent Explanation:\n\n");
        strcat(explanation, "The code appears to implement a programming concept.\n");
        strcat(explanation, "For detailed explanation, please provide:\n");
        strcat(explanation, "- The specific programming language\n");
        strcat(explanation, "- The context/purpose of the code\n");
        strcat(explanation, "- Any specific sections you want explained");
    }
    return 0;
}

