const Benchmark = require('./Benchmark');

/**
 * Algorithm: Split String by Character
 * Complexity: O(n)
 * Description: Basic string splitting implementation using split()
 */
function split_string(text, delimiter) {
    return text.split(delimiter);
}

// # 1️⃣ Test data
const text = "hello,world,this,is,a,test";
const delimiter = ",";
// ---
// Get iterations from command line argument, default to 10000
const iterations = process.argv[2] ? parseInt(process.argv[2]) : 10000;

// # 2️⃣ Run benchmark
const benchmark = new Benchmark(iterations);
benchmark.measure(split_string, [text, delimiter]);

// # 3️⃣ Print results
benchmark.print();