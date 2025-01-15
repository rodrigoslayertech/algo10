#include <stdio.h>
#include <stdarg.h>

#include "Benchmark.h"


void benchmark_init(Benchmark* b, int iterations) {
    b->iterations = iterations;
    b->time = 0;
    b->time_per_iteration = 0;
}

void* benchmark_measure(Benchmark* b, GenericFunction fn, ...) {
    va_list args;
    clock_t start = clock();

    for(int i = 0; i < b->iterations; i++) {
        va_start(args, fn);

        if (i == b->iterations - 1) {
            // Guarda último resultado
            b->last_result = fn(args);
        } else {
            fn(args);
        }

        va_end(args);
    }

    b->time = (double)(clock() - start) / CLOCKS_PER_SEC;
    b->time_per_iteration = b->time / b->iterations;

    return b->last_result;
}

void benchmark_print(Benchmark* b) {
    printf("%.10f s\n", b->time);
}
