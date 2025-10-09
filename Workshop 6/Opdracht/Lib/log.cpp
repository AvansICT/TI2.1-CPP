#include <iostream>
#include "log.hpp"

void LogOperatingSystem(void)
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

void LogCompiler(void)
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