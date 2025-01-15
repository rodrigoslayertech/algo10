package main

import (
	"os"
	"strconv"
	"strings"
	"./Benchmark"
)

// SplitString splits a string by a given delimiter
func SplitString(text, delimiter string) []string {
	return strings.Split(text, delimiter)
}

func main() {
	// # 1️⃣ Test data
	text := "hello,world,this,is,a,test"
	delimiter := ","
	// ---
	// Get iterations from command line argument, default to 10000
	iterations := 10000
	if len(os.Args) > 1 {
		iterations, _ = strconv.Atoi(os.Args[1])
	}

	// # 2️⃣ Run benchmark
	Benchmark := Benchmark.NewBenchmark(iterations)
	Benchmark.Measure(SplitString, text, delimiter)

	// # 3️⃣ Print results
	Benchmark.Print()
}
