#include "..\lib\omptimer.hpp"
#include "..\lib\windowstimer.hpp"
#include <vector>
#include <iostream>
#include<algorithm>
#include <omp.h>

#define FIBONACCI_NR 45
// Sequential recursive Fibonacci
long long fibonacci(long long n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 2) + fibonacci(n - 1);
}

// recursive Fibonacci with tasks
long long fibonacciOpenMP(int n) {
    if (n <= 1) return n;

    long long x, y;
#pragma omp task shared(x) if(n>20)
    x = fibonacciOpenMP(n - 1);

#pragma omp task shared(y) if(n>20)
    y = fibonacciOpenMP(n - 2);

#pragma omp taskwait
    return x + y;
}

int main() {
    WindowsTimer t1;
    OmpTimer t2;
    long long result_seq;
    std::vector<long long> results_seq(FIBONACCI_NR);

	std::cout << "OpenMP Fibonacci Sequence\n";
    // Sequential
    t1.startTimer();
    result_seq = fibonacci(FIBONACCI_NR);
    t1.stopTimer();
    std::cout << "Sequential fibonacci(" << FIBONACCI_NR << ") = " << result_seq
        << ", Time = " << t1.elapsedTime() << " sec\n";
    t1.startTimer();
    for (int i = 1; i <= FIBONACCI_NR; i++) {
        results_seq[i - 1] = fibonacci(i);
    }
    t1.stopTimer();
    int idx = 1;
    // log with foreach and lambda
    std::for_each(results_seq.begin(), results_seq.end(), [&](long long val) {
        std::cout << "Fib(" << idx++ << ") = " << val << std::endl;
        });
    std::cout << "t1 elapsed: " << t1.elapsedTime() << " sec\n";

    int iCPU = omp_get_num_procs(); // Get the number of processors in this system
    std::cout << "Using number of cores: " << iCPU << std::endl;
    omp_set_num_threads(iCPU); // Now set the number of threads

    // Parallel
    t2.startTimer();
    long long result_par;
    std::vector<long long> results_par(FIBONACCI_NR);
#pragma omp parallel
    {
#pragma omp single
        result_par = fibonacciOpenMP(FIBONACCI_NR);
    }
    t2.stopTimer();
    std::cout << "Parallel OpenMP fibonacci(" << FIBONACCI_NR << ") = " << result_par
        << ", Time = " << t2.elapsedTime() << " sec\n";


    // Parallel
    t2.startTimer();
#pragma omp parallel
    {
#pragma omp for
        for (int i = 1; i <= FIBONACCI_NR; i++) {
#pragma omp single
            results_par[i - 1] = fibonacciOpenMP(i);
        }
    }
    t2.stopTimer();

    // range - based for with index
    idx = 1;
    for (const auto& val : results_par) {
        std::cout << "Fib(" << idx++ << ") = " << val << std::endl;
    }
    std::cout << "Parallel OpenMP elapsed: " << t2.elapsedTime() << " sec\n";
    return 0;
}
