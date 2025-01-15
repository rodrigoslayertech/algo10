#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Benchmark.c"

typedef struct {
    char** tokens;
    int count;
} SplitResult;

void* split_string(va_list args) {
    const char* text = va_arg(args, const char*);
    const char* delimiter = va_arg(args, const char*);
    
    // Single buffer for entire string
    static char buffer[1024];
    strcpy(buffer, text);
    
    // Result with fixed array for pointers
    static SplitResult static_result;
    static char* tokens[1024];
    static_result.tokens = tokens;
    static_result.count = 0;
    
    // Split directly into the buffer
    char* token = strtok(buffer, delimiter);
    while (token != NULL && static_result.count < 1024) {
        static_result.tokens[static_result.count++] = token;
        token = strtok(NULL, delimiter);
    }
    
    return &static_result;
}

int main(int argc, char *argv[]) {
    // # 1️⃣ Test data
    const char* text = "hello,world,this,is,a,test";
    const char* delimiter = ",";
    // ---
    // Get iterations
    int iterations = argc > 1 ? atoi(argv[1]) : 1000;

    // # 2️⃣ Benchmark
    Benchmark b;
    benchmark_init(&b, iterations);
    benchmark_measure(&b, split_string, text, delimiter);

    // # 3️⃣ Print results
    benchmark_print(&b);

    return 0;
}
