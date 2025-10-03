#ifndef PATIENT_HPP
#define PATIENT_HPP

#include "person.hpp"
#include <memory>
// ---------- Derived Class: Rule of Five ----------
class Patient : public Person {
    std::unique_ptr<std::string> diagnosis;
    std::unique_ptr<int[]> records;
    int size;

public:
    Patient(const std::string& n, int a, const std::string& diag, int count);

    // Rule of Five
    ~Patient();
    Patient(const Patient& other);
    Patient& operator=(const Patient& other);
    Patient(Patient&& other) noexcept;
    Patient& operator=(Patient&& other) noexcept;

    void printInfo() const override;
};

#endif
