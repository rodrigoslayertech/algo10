#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <time.h>
#include <stdarg.h>

typedef void* (*GenericFunction)(va_list args);

typedef struct {
    int iterations;
    double time;
    double time_per_iteration;
    void* last_result;
} Benchmark;

void benchmark_init(Benchmark* b, int iterations);
void* benchmark_measure(Benchmark* b, GenericFunction fn, ...);
void benchmark_print(Benchmark* b);

#endif