// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "log.hpp"


int main()
{
    std::cout << "Workshop 5!\n";
    std::cout << __DATE__ << " " << __TIME__ << std::endl; // log date and time of compilation, not runtime
    return 0;
}
