#include <iostream>
#include <vector>
#include <cstdlib> // rand()
#include "log.hpp"
#include "chronotimer.hpp"
#include "omptimer.hpp"

int main() {
    std::cout << "reductie\n";
    std::cout << __DATE__ << " " << __TIME__ << std::endl; // log date and time of compilation, not runtime
    LogOperatingSystem();
    LogCompiler();
    LogCxxStandard();

    ChronoTimer t1;
	OmpTimer t2;
    const long long N = 10000000;
    std::vector<int> data(N);

    // Vul array met willekeurige getallen van 1 t/m 10
    for (long long i = 0; i < N; ++i)
        data[i] = rand() % 10 + 1;

    // Seri�le berekening van som
    long long sum = 0;
    t1.startTimer();

    for (long long i = 0; i < N; ++i) {
        sum += data[i];
    }
    t1.stopTimer();
   
    std::cout << "Serial sum = " << sum
        << ", Time = " << t1.elapsedTime() << " s\n";

	// TODO Parallelle berekening van som met OpenMP reductie


    return 0;
}