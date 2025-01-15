
<?php
require_once __DIR__ . '/Benchmark.php';

/**
 * Algorithm: Reverse String (Variation 2)
 * Complexity: O(n)
 * Description: Reverses a given string using a for loop.
 */
function reverse_string_v2(string $text): string {
    $reversed = '';
    for ($i = strlen($text) - 1; $i >= 0; $i--) {
        $reversed .= $text[$i];
    }
    return $reversed;
}

// # 1️⃣ Test data
$text = "hello world";
// ---
# Get iterations from command line argument, default to 10000
$iterations = isset($argv[1]) ? (int)$argv[1] : 10000;

// # 2️⃣ Run benchmark
$Benchmark = new Benchmark(iterations: $iterations);
$Benchmark->measure('reverse_string_v2', [$text]);

// # 3️⃣ Print results
$Benchmark->print();