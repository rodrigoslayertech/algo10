<?php
require_once __DIR__ . '/Benchmark.php';

/**
 * Algorithm: Split String by Character
 * Complexity: O(n)
 * Description: Basic string splitting implementation using explode()
 */
function split_string_by_character(string $text, string $delimiter): array {
    return explode($delimiter, $text);
}

// # 1️⃣ Test data
$text = "hello,world,this,is,a,test";
$delimiter = ",";
// ---
// Get iterations from command line argument, default to 10000
$iterations = isset($argv[1]) ? (int)$argv[1] : 10000;

// # 2️⃣ Run benchmark
$Benchmark = new Benchmark(iterations: $iterations);
$Benchmark->measure('split_string_by_character', [$text, $delimiter]);

// # 3️⃣ Print results
$Benchmark->print();

