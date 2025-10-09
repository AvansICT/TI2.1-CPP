#include <iostream>
#include <string>
#include "log.hpp"

int main() {
    std::cout << "Workshop 7!\n";
    std::cout << __DATE__ << " " << __TIME__ << std::endl; // log date and time of compilation, not runtime
    return 0;
}
