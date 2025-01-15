#[path = "Benchmark.rs"]
mod benchmark;

use benchmark::Benchmark;

fn split_string(text: &str, delimiter: char) -> Vec<&str> {
    text.split(delimiter).collect()
}

fn main() {
    // # 1️⃣ Test data
    let text = "hello,world,this,is,a,test";
    let delimiter = ',';
    // ---
    // Get iterations from command line argument, default to 10000
    let args: Vec<String> = std::env::args().collect();
    let iterations = if args.len() > 1 {
        args[1].parse().unwrap_or(10000)
    } else {
        10000
    };

    // # 2️⃣ Run benchmark
    let mut benchmark = Benchmark::new(iterations);
    benchmark.measure(|| {
        split_string(text, delimiter);
    });

    // # 3️⃣ Print results
    benchmark.print();
}
