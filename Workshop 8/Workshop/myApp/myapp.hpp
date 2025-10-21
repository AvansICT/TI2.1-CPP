#pragma once
#include <stdexcept>

namespace myApp {

    // Basic operations without class just for demo working without class in unit tests
    int add(int a, int b) ;
    int subtract(int a, int b);
    int multiply(int a, int b);
    int divide(int a, int b);
    int modulus(int a, int b);

    // Basic operations with class just for demo working with class in unit tests
    class MathFunctions {
    public:
        // Constructor
        MathFunctions() = default;

        // Basisbewerkingen
        int add(int a, int b) const;
        int subtract(int a, int b) const;
        int multiply(int a, int b) const;
        int divide(int a, int b) const;   // gooit std::invalid_argument bij deling door nul
        int modulus(int a, int b) const;  // gooit std::invalid_argument bij modulo door nul
    };
} // namespace myApp
