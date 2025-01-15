import sys
from Benchmark import Benchmark

def split_string(text: str, delimiter: str) -> list:
    """
    Algorithm: Split String by Character
    Complexity: O(n)
    Description: Basic string splitting implementation using built-in split()
    """
    return text.split(delimiter)

if __name__ == "__main__":
    ## 1️⃣ Test data
    text = "hello,world,this,is,a,test"
    delimiter = ","
    # ---
    # Get iterations from command line argument, default to 10000
    iterations = int(sys.argv[1]) if len(sys.argv) > 1 else 10000

    ## 2️⃣ Run benchmark
    benchmark = Benchmark(iterations=iterations)
    result = benchmark.measure(split_string, (text, delimiter))
    
    ## 3️⃣ Print results
    benchmark.print()
