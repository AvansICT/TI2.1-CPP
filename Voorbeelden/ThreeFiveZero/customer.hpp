#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include "person.hpp"

// ---------- Derived Class: Rule of Three ----------
class Customer : public Person {
    char* customerId;
    int* purchases;
    int size;

public:
    Customer(const std::string& n, int a, const char* id, int count);
    ~Customer();

    // Rule of Three
    Customer(const Customer& other);
    Customer& operator=(const Customer& other);

    void printInfo() const override;
};

#endif
