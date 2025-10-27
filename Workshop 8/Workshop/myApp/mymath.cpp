#include "mymath.hpp"

namespace myMath {

// methods without class
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}

int modulus(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Modulo by zero");
    }
    return a % b;
}

// Class functions
int MathFunctions::add(int a, int b) const {
    return a + b;
}

int MathFunctions::subtract(int a, int b) const {
    return a - b;
}

int MathFunctions::multiply(int a, int b) const {
    return a * b;
}

int MathFunctions::divide(int a, int b) const {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}

int MathFunctions::modulus(int a, int b) const {
    if (b == 0) {
        throw std::invalid_argument("Modulo by zero");
    }
    return a % b;
}

} // namespace myMath
