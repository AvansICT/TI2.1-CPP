#include <omp.h>
#include <iostream>

using namespace std;

long long fib(long long n) {
	if (n < 2) {
		return 1;
	}
	return fib(n - 2) + fib(n - 1);
}

int main() {
	std::cout << "OpenMPFibonacci Example!\n";
	std::cout << __DATE__ << " " << __TIME__ << std::endl; // log date and time of compilation, not runtime
	long long n = 0;

	// Set number of threads same as number of cores
	omp_set_num_threads(omp_get_num_procs());

#pragma omp parallel private(n)
	{
#pragma omp for schedule(dynamic, 1)
		for (n = 0; n <= 45; n++) {
			printf("Fib(%lld): %lld\n", n, fib(n));
		}

	}

#if defined(_DEBUG) && defined(_MSC_FULL_VER)
	__debugbreak(); // hardcoded breakpoint for debug build only
#endif
	return 0;
}

