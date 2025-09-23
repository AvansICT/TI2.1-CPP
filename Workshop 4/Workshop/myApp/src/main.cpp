// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include "log.hpp"


void LogOperatingSystem()
{
#if defined(_WIN32) && defined(_WIN64)
	std::cout << "Running on Windows 64-bit" << std::endl;
#elif defined(_WIN32)
	std::cout << "Running on Windows 32-bit" << std::endl;
#elif defined(__APPLE__) || defined(__MACH__)
	std::cout << "Running on macOS" << std::endl;
#elif defined(__linux__)
	std::cout << "Running on Linux" << std::endl;
#elif defined(__unix__)
	std::cout << "Running on Unix" << std::endl;
#elif defined(_POSIX_VERSION)
	std::cout << "Running on POSIX-compliant OS" << std::endl;
#else
	std::cout << "Unknown OS" << std::endl;
#endif
}

void LogCompiler()
{
#if defined(__clang__)
	std::cout << "Compiled with Clang version: " << __clang_version__ << std::endl;
#elif defined(__GNUC__) || defined(__GNUG__)
	std::cout << "Compiled with GCC version: " << __VERSION__ << " (" << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << ")" << std::endl;
#elif defined(_MSC_FULL_VER)
	std::cout << "Compiled with MSVC version: " << _MSC_FULL_VER << std::endl;
#else
	std::cout << "Unknown compiler" << std::endl;
#endif
}

int main()
{
	std::cout << "myApp!\n";
	std::cout << __DATE__ << " " << __TIME__ << std::endl; // log date and time of compilation, not runtime
	LogOperatingSystem();
	LogCompiler();
	LOG_DEBUG
	// Some fun with random numbers
	std::srand(static_cast<unsigned>(std::time(nullptr))); // init random

	// Fun "Hello World" greeting
	std::cout << "Hello, student! \n";

	// Random fun fact / tip / joke
	std::vector<std::string> funStuff = {
		"Did you know? C++ was created in 1985!",
		"Random tip: Take a short break every hour. ",
		"Fun fact: The first computer bug was an actual moth!",
		"Keep calm and code on! ",
		"Your lucky number today: " + std::to_string(std::rand() % 100 + 1)
	};

	int randomIndex = std::rand() % funStuff.size();
	std::cout << funStuff[randomIndex] << "\n";

	return 0;
}