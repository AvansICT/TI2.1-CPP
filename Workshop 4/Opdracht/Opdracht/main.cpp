// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <print>    //C++23
#include "log.hpp"


using namespace std;


#define FIRSTNUM    5
#define SECONDNUM   6

// Global function
int globalAdd(int x, int y) {
    return x + y;
}

int main()
{
    std::print("Hello, Opdracht\n");    // C++23 feature

    return 0;
}
