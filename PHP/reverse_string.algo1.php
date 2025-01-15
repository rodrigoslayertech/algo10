
<?php
require_once __DIR__ . '/Benchmark.php';

/**
 * Algorithm: Reverse String
 * Complexity: O(n)
 * Description: Reverses a given string using strrev()
 */
function reverse_string(string $text): string {
    return strrev($text);
}

// # 1️⃣ Test data
$text = "hello world";
// ---
// Get iterations from command line argument, default to 10000
$iterations = isset($argv[1]) ? (int)$argv[1] : 10000;

// # 2️⃣ Run benchmark
$Benchmark = new Benchmark(iterations: $iterations);
$Benchmark->measure('reverse_string', [$text]);

// # 3️⃣ Print results
$Benchmark->print();