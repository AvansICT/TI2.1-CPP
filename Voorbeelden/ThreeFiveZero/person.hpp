#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <iostream>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& n, int a) : name(n), age(a) {}
    virtual ~Person() = default;

    virtual void printInfo() const = 0; // abstract
};

#endif
