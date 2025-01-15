package Benchmark

import (
	"fmt"
	"time"
)

type Benchmark struct {
	iterations int
	results    map[string]float64
}

func NewBenchmark(iterations int) *Benchmark {
	return &Benchmark{
		iterations: iterations,
		results:    make(map[string]float64),
	}
}

func (b *Benchmark) Measure(fn func(string, string) []string, params ...string) {
	start := time.Now()

	for i := 0; i < b.iterations; i++ {
		fn(params[0], params[1])
	}

	elapsed := time.Since(start).Seconds()

	b.results["time"] = elapsed
	b.results["iterations"] = float64(b.iterations)
	b.results["time_per_iteration"] = elapsed / float64(b.iterations)
}

func (b *Benchmark) Print() {
	fmt.Printf("%.10f s\n", b.results["time"])
}
