#include <iostream>
#include <unordered_map>
#include <chrono>
#include "chronotimer.hpp"
#include "windowstimer.hpp"

#define FIBONACCI_NR 45

std::unordered_map<long long, long long> fibCache;

inline long long fib_cache(long long n)
{
    auto it = fibCache.find(n);
    if (it != fibCache.end())
        return it->second;

    if (n <= 1)
    {
        return n;
    }

    auto fib = fib_cache(n - 1) + fib_cache(n - 2);
    fibCache[n] = fib;
    return fib;
}

long long fibonacci(long long n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 2) + fibonacci(n - 1);
}

int main()
{
    std::cout << "Fibonacci Sequence using C++\n";
    std::vector<long long> results(FIBONACCI_NR);
    // fibonacci measured with chronotimer
    ChronoTimer t1;
    t1.startTimer();
    for (int i = 1; i <= FIBONACCI_NR; i++) {
        results[i - 1] = fibonacci(i);
    }
    t1.stopTimer();
    for (int i = 1; i <= FIBONACCI_NR; i++) {
        std::cout << "Fib(" << i << ") = " << results[i - 1] << std::endl;
    }
    std::cout << "t1 elapsed: " << t1.elapsedTime() << " sec\n";

    // fibonacci measured with windowtimer
    WindowsTimer t2;
    t2.startTimer();
    for (int i = 1; i <= FIBONACCI_NR; i++) {
        results[i - 1] = fibonacci(i);
    }
    t2.stopTimer();
    for (int i = 1; i <= FIBONACCI_NR; i++) {
        std::cout << "Fib(" << i << ") = " << results[i - 1] << std::endl;
    }
    std::cout << "t2 elapsed: " << t2.elapsedTime() << " sec\n";

	// fibonacci without cache
    long long fib;
    WindowsTimer t3;
	t3.startTimer();
    fib = fibonacci(FIBONACCI_NR);
    t3.stopTimer();
	std::cout << "Fibonacci without cache: " << fib << " took: " << t3.elapsedTime() << " sec\n";
	// fibonacci with cache
    long long fibC;
	WindowsTimer t4;
    t4.startTimer();
    fibC = fib_cache(FIBONACCI_NR);
    t4.stopTimer();
    std::cout << "Fibonacci cached: " << fib << " took: " << t4.elapsedTime() << " sec\n";

    return 0;
}