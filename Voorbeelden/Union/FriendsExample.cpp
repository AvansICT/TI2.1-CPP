#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <xatomic.h>
#include <iterator>
#include <sstream>


using namespace std;


constexpr double operator"" _CelsiusToFahrenheit(long double celsius)
{
    return celsius * 9.0 / 5.0 + 32.0;
}

constexpr double operator"" _ZoMaarEenOptelling(long double value)
{
    return value + 1.0;
}

int main()
{
    double temperature = 22.0_CelsiusToFahrenheit;
    std::cout << "22 graden Celsius is " << temperature << " graden Fahrenheit." << std::endl;

    double val = 1.0_ZoMaarEenOptelling;
    std::cout << "ZoMaarEenOmzetting " << val << std::endl;

    return 0;
}
