import time
from typing import Callable, Any, Dict
from dataclasses import dataclass

class Benchmark:
    def __init__(self, iterations: int = 10000):
        self.iterations = iterations
        self.results = {}

    def measure(self, fn: Callable, params: tuple = ()) -> Dict[str, float]:
        start = time.time()

        for _ in range(self.iterations):
            fn(*params)

        end = time.time()

        elapsed = end - start

        self.results = {
            'time': format(elapsed, '.10f'),
            'iterations': self.iterations,
            'time_per_iteration': format(elapsed / self.iterations, '.10f')
        }
    def print(self):
        print(f"{self.results['time']} s")