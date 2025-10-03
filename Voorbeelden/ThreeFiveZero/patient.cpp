#include "patient.hpp"
#include <cstdlib>

Patient::Patient(const std::string& n, int a, const std::string& diag, int count)
    : Person(n, a), diagnosis(std::make_unique<std::string>(diag)), size(count) {
    std::cout << "[Patient] Constructor called\n";
    records = std::make_unique<int[]>(size);
    for (int i = 0; i < size; i++) records[i] = rand() % 1000;
}

Patient::Patient(const Patient& other) : Person(other.name, other.age), size(other.size) {
    std::cout << "[Patient] Copy constructor called\n";
    diagnosis = std::make_unique<std::string>(*other.diagnosis);
    records = std::make_unique<int[]>(size);
    for (int i = 0; i < size; i++) records[i] = other.records[i];
}

Patient& Patient::operator=(const Patient& other) {
    std::cout << "[Patient] Copy assignment called\n";
    if (this != &other) {
        name = other.name;
        age = other.age;
        diagnosis = std::make_unique<std::string>(*other.diagnosis);
        size = other.size;
        records = std::make_unique<int[]>(size);
        for (int i = 0; i < size; i++) records[i] = other.records[i];
    }
    return *this;
}

Patient::Patient(Patient&& other) noexcept
    : Person(std::move(other.name), other.age),
    diagnosis(std::move(other.diagnosis)),
    records(std::move(other.records)), size(other.size) {
    std::cout << "[Patient] Move constructor called\n";
    other.size = 0;
}

Patient& Patient::operator=(Patient&& other) noexcept {
    std::cout << "[Patient] Move assignment called\n";
    if (this != &other) {
        name = std::move(other.name);
        age = other.age;
        diagnosis = std::move(other.diagnosis);
        records = std::move(other.records);
        size = other.size;
        other.size = 0;
    }
    return *this;
}

Patient::~Patient() {
    std::cout << "[Patient] Destructor called\n";
}

void Patient::printInfo() const {
    std::cout << "Patient: " << name << ", Age: " << age
        << ", Diagnosis: " << *diagnosis << ", Records: ";
    for (int i = 0; i < size; i++) std::cout << records[i] << " ";
    std::cout << std::endl;
}
