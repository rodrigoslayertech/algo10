# Algo10

Algorithm studies. Compared in different languages and variations with benchmarks.

## Algorithms

- split_string_by_character
- reverse_string

## Project Structure

Below is an example of how algorithms are structured in directories and folders.

```txt
algo10/
├── C/
│   ├── Benchmark.h
│   ├── Benchmark.c
│   ├── split_string_by_character.algo1.c
│   ├── split_string_by_character.algo2.c
│   └── ...Other algorithms or variations of the same algorithm here...
├── CPP/
│   ├── Benchmark.h
│   ├── Benchmark.cpp
│   ├── split_string_by_character.algo1.cpp
│   ├── split_string_by_character.algo2.cpp
│   └── ...Other algorithms or variations of the same algorithm here...
├── Go/
│   ├── Benchmark.go
│   ├── split_string_by_character.algo1.go
│   └── ...Other algorithms or variations of the same algorithm here...
├── PHP/
│   ├── Benchmark.php
│   ├── split_string_by_character.algo1.php
│   ├── split_string_by_character.algo2.php
│   └── ...Other algorithms or variations of the same algorithm here...
├── Javascript/
│   ├── Benchmark.js
│   ├── split_string_by_character.algo1.js
│   ├── split_string_by_character.algo2.js
│   └── ...Other algorithms or variations of the same algorithm here...
├── Python/
│   ├── Benchmark.py
│   ├── split_string_by_character.algo1.py
│   ├── split_string_by_character.algo2.py
│   └── ....Other algorithms or variations of the same algorithm here...
├── Rust/
│   ├── Benchmark.rs
│   ├── split_string_by_character.algo1.rs
│   └── ...Other algorithms or variations of the same algorithm here...
└── README.md
```

## Rules

1. Language names like folders in the root folder start with a capital letter
2. Algorithm names MUST be identical across all languages (e.g., 'split_string_by_character' should be used consistently, not 'explode_string' in one language and 'split_string_by_character' in another)
3. Each algorithm can have multiple implementations (variations)
4. Variations of algorithms written in the same language are identified with the suffix `.algo` + `n`, where `n` is the number of the algorithm variation: algo1, algo2, etc. There can only be up to 10 variations of the same algorithm.
5. Each language must have its own Benchmark module.
6. The Benchmark module file name for each language must start with an uppercase letter: `Benchmark`.
7. All implementations MUST include benchmarks for performance comparison

### File Naming Convention

- Use snake_case for algorithm names.
- Keep names simple and descriptive. You should be able to identify exactly what the algorithm does by the file name.
- Always use English terms.
- File pattern: `<language_name>/<algorithm_name>.algo<variation_number>.<extension>`

## Scope

### Programming Languages

- C
- CPP
- Go
- Javascript
- PHP
- Python
- Rust

Feel free to add other languages.

### Runtimes

#### Javascript

- NodeJS
- Bun

Feel free to add other runtimes.

## Running Tests

```bash
bash run.sh
```
