use std::time::Instant;

pub struct Benchmark {
    iterations: usize,
    time: f64,
    time_per_iteration: f64,
}

impl Benchmark {
    pub fn new(iterations: usize) -> Self {
        Self {
            iterations,
            time: 0.0,
            time_per_iteration: 0.0,
        }
    }

    pub fn measure<F>(&mut self, mut func: F)
    where
        F: FnMut(),
    {
        let start = Instant::now();

        for _ in 0..self.iterations {
            func();
        }

        let duration = start.elapsed();
        self.time = duration.as_secs_f64();
        self.time_per_iteration = self.time / self.iterations as f64;
    }

    pub fn print(&self) {
        println!("{:.10} s", self.time);
    }
}
