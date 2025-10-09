#include <iostream>
#include <vector>
#include <cstdlib> // rand()
#include "chronotimer.hpp"
#include "omptimer.hpp"

int main() {
    std::cout << "reductie\n";
    std::cout << __DATE__ << " " << __TIME__ << std::endl; // log date and time of compilation, not runtime
    ChronoTimer t1;
	OmpTimer t2;
    const long long N = 10000000;
    std::vector<int> data(N);

    // Vul array met willekeurige getallen van 1 t/m 10
    for (long long i = 0; i < N; ++i)
        data[i] = rand() % 10 + 1;

    // Seriële berekening van som
    long long sum = 0;
    t1.startTimer();

    for (long long i = 0; i < N; ++i) {
        sum += data[i];
    }
    t1.stopTimer();
   
    std::cout << "Serial sum = " << sum
        << ", Time = " << t1.elapsedTime() << " s\n";

	// TODO Parallelle berekening van som met OpenMP reductie

    // ------------------------
    // Parallel met OpenMP reductie
    // ------------------------
    long long sum_parallel = 0;
    t2.startTimer();
    int iCPU = omp_get_num_procs(); // Get the number of processors in this system
    omp_set_num_threads(iCPU); // Now set the number of threads
#pragma omp parallel for reduction(+:sum_parallel)
    for (long long i = 0; i < N; ++i) {
        sum_parallel += data[i];
    }
    t2.stopTimer();
    std::cout << "Parallel sum = " << sum_parallel
        << ", Time = " << t2.elapsedTime() << " s\n";

    return 0;
}
