class Benchmark {
    constructor(iterations = 10000) {
        this.iterations = iterations;
        this.results = {};
    }

    measure(fn, params = []) {
        const start = performance.now();

        for (let i = 0; i < this.iterations; i++) {
            fn(...params);
        }

        const end = performance.now();
        const elapsed = (end - start) / 1000; // Convert to seconds

        this.results = {
            time: elapsed.toFixed(10),
            iterations: this.iterations,
            time_per_iteration: (elapsed / this.iterations).toFixed(10)
        };
        
        return this.results;
    }

    print() {
        console.log(`${this.results.time} s`);
    }
}

module.exports = Benchmark;
