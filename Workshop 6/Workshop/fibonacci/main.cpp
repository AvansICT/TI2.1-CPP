#include <iostream>
#include <string>

using namespace std;

static unsigned int nFibRecursiveAcc(unsigned int n, unsigned int a, unsigned int b) {
	if (n <= 1)
		return a;
	return nFibRecursiveAcc(n - 1, b, a + b + 1);
}

static unsigned long nFibRecursive2(unsigned int n) {
	return nFibRecursiveAcc(n, 1, 1);
}


int main() {
	std::cout << "fibonacci\n";
	std::cout << __DATE__ << " " << __TIME__ << std::endl; // log date and time of compilation, not runtime

	for (int i = 1; i <= 45; i++) {
		cout << "Id (" << i << "): " << nFibRecursive2(i) << endl;
	}

#if defined(_DEBUG) && defined(_MSC_FULL_VER)
	__debugbreak(); // hardcoded breakpoint for debug build only
#endif
	return 0;
}


