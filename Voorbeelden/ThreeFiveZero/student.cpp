#include "student.hpp"
#include <cstdlib>

Student::Student(const std::string& n, int a, const std::string& prog, int count)
    : Person(n, a), studyProgram(prog) {
    grades.resize(count);
    for (int& g : grades) g = rand() % 100;
}

void Student::printInfo() const {
    std::cout << "Student: " << name << ", Age: " << age
        << ", Program: " << studyProgram << ", Grades: ";
    for (auto g : grades) std::cout << g << " ";
    std::cout << std::endl;
}
