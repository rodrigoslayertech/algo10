#include <iostream>
#include <chrono>
#include <functional>
#include <iomanip>

class Benchmark {
private:
    int iterations;
    double elapsed_time;

public:
    Benchmark(int iterations = 10000) : iterations(iterations), elapsed_time(0) {}

    void measure(const std::function<void()>& func) {
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < iterations; ++i) {
            func();
        }

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = end - start;

        elapsed_time = elapsed.count();
    }

    void print() const {
        std::cout << std::fixed << std::setprecision(10) << elapsed_time << " s\n";
    }
};
