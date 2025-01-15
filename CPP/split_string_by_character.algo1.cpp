#include <iostream>
#include <vector>
#include "Benchmark.h"

std::vector<std::string> split_string_by_character(const std::string& text, char delimiter) {
    std::vector<std::string> result;
    result.reserve(10);

    size_t start = 0;
    size_t end = text.find(delimiter);

    while (end != std::string::npos) {
        result.push_back(text.substr(start, end - start));
        start = end + 1;
        end = text.find(delimiter, start);
    }

    result.push_back(text.substr(start));

    return result;
}

int main(int argc, char* argv[]) {
    // # 1️⃣ Test data
    std::string text = "hello,world,this,is,a,test";
    char delimiter = ',';

    int iterations = (argc > 1) ? std::stoi(argv[1]) : 10000;

    // # 2️⃣ Run benchmark
    Benchmark benchmark(iterations);
    benchmark.measure([&]() {
        split_string_by_character(text, delimiter);
    });

    // # 3️⃣ Print results
    benchmark.print();
    return 0;
}
