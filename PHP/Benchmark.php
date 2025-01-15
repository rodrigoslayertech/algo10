<?php

class Benchmark
{
    private int $iterations;
    private array $results = [];


    public function __construct (int $iterations = 10000)
    {
        $this->iterations = $iterations;
    }

    public function measure (callable $fn, array $params = []): void
    {
        $start = microtime(true);

        for ($i = 0; $i < $this->iterations; $i++) {
            $fn(...$params);
        }

        $end = microtime(true);

        $elapsed = $end - $start;

        $this->results = [
            'time' => number_format(
                $elapsed,
                10,
                '.',
                ''
            ),
            'iterations' => $this->iterations,
            'time_per_iteration' => number_format(
                $elapsed / $this->iterations,
                10,
                '.',
                ''
            )
        ];
    }
    public function print (): void
    {
        echo "{$this->results['time']} s\n";
    }
}
