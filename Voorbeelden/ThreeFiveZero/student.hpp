#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "person.hpp"
#include <vector>
// ---------- Derived Class: Rule of Zero ----------
class Student : public Person {
    std::string studyProgram;
    std::vector<int> grades;

public:
    Student(const std::string& n, int a, const std::string& prog, int count);

    void printInfo() const override;
};

#endif
