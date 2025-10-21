#include <iostream>
#include <vector>
#include "log.hpp"
#include "myapp.hpp"

#define N1 12
#define N2 4

int main() {
    // simple basic app used for unit tests
    std::cout << "myApp!\n";
    std::cout << __DATE__ << " " << __TIME__ << std::endl; // log date and time of compilation, not runtime

	// use the functions from myapp
    std::cout << "add result:" << myApp::add(N1, N2) << std::endl;
    std::cout << "sub result:" << myApp::subtract(N1, N2) << std::endl;
    std::cout << "mul result:" << myApp::multiply(N1, N2) << std::endl;
    std::cout << "div result:" << myApp::divide(N1, N2) << std::endl;
    std::cout << "mod result:" << myApp::modulus(N1, N2) << std::endl;
    
    myApp::MathFunctions M;
    // Use the MathFunctions class 
    std::cout << "add class result:" << M.add(N1, N2) << std::endl;
    std::cout << "sub class result:" << M.subtract(N1, N2) << std::endl;
    std::cout << "mul class result:" << M.multiply(N1, N2) << std::endl;
    std::cout << "div class result:" << M.divide(N1, N2) << std::endl;
    std::cout << "mod class result:" << M.modulus(N1, N2) << std::endl;

    return 0;
}
