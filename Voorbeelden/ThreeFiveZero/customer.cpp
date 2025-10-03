#include "customer.hpp"
#include <cstring>
#include <cstdlib>

Customer::Customer(const std::string& n, int a, const char* id, int count)
    : Person(n, a), size(count) {
    std::cout << "[Customer] Constructor called\n";
    customerId = new char[strlen(id) + 1];
    strcpy_s(customerId, strlen(id) + 1, id);
    purchases = new int[size];
    for (int i = 0; i < size; i++) purchases[i] = rand() % 500;
}

Customer::~Customer() {
    std::cout << "[Customer] Destructor called\n";
    delete[] customerId;
    delete[] purchases;
}

Customer::Customer(const Customer& other) : Person(other.name, other.age), size(other.size) {
    std::cout << "[Customer] Copy constructor called\n";
    customerId = new char[strlen(other.customerId) + 1];
    strcpy_s(customerId, strlen(other.customerId) + 1, other.customerId);
    purchases = new int[size];
    for (int i = 0; i < size; i++) purchases[i] = other.purchases[i];
}

Customer& Customer::operator=(const Customer& other) {
    std::cout << "[Customer] Copy assignment called\n";
    if (this != &other) {
        name = other.name;
        age = other.age;
        delete[] customerId;
        customerId = new char[strlen(other.customerId) + 1];
        strcpy_s(customerId, strlen(other.customerId) + 1, other.customerId);
        delete[] purchases;
        size = other.size;
        purchases = new int[size];
        for (int i = 0; i < size; i++) purchases[i] = other.purchases[i];
    }
    return *this;
}


void Customer::printInfo() const {
    std::cout << "Customer: " << name << ", Age: " << age
        << ", CustomerID: " << customerId << ", Purchases: ";
    for (int i = 0; i < size; i++) std::cout << purchases[i] << " ";
    std::cout << std::endl;
}
