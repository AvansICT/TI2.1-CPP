// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "log.hpp"

class InheritanceBase {
public:
    void sayHello() {
        std::cout << "Hello from InheritanceBase!" << std::endl;
    }
};

class InheritanceDerived : public InheritanceBase {   // Derived erft van Base
public:
    void sayBye() {
        std::cout << "Goodbye from InheritanceDerived!" << std::endl;
    }
};

static void demonstrateInheritance() {
    InheritanceDerived d;
    d.sayHello(); // Inherited method from Base
    d.sayBye();   // Method from Derived
}

class A {
public:
    void greet() { std::cout << "Hello from A\n"; }
};

class B {
public:
    void greet() { std::cout << "Hello from B\n"; }
};

class C : public A, public B {
public:
	void greetC() { std::cout << "Hello from C\n"; }
};

static void demonstrateMultipleInheritance(void) {
    C obj;
    // obj.greet(); // fout: ambigu, A::greet of B::greet?
    obj.A::greet(); // correct, expliciet A
    obj.B::greet(); // correct, expliciet B
    obj.greetC();
}

class PolymorphismBase {
public:
    virtual void greet() { std::cout << "Hello from PolymorphismBase\n"; }
};

class PolymorphismDerived1 : public PolymorphismBase {
public:
};

class PolymorphismDerived2 : public PolymorphismBase {
public:
    void greet() override { std::cout << "Hello from Derived override\n"; }
};

static void demonstratePolymorphism(void) {
    PolymorphismBase* obj1 = new PolymorphismDerived1();
    obj1->greet();  // Roept PolymorphismBase::greet() aan
    PolymorphismBase* obj2 = new PolymorphismDerived2();
    obj2->greet();  // Roept PolymorphismDerived2::greet() aan
    delete obj1,obj2;
}

int main()
{
    std::cout << "Workshop 4!\n";
    std::cout << __DATE__ << " " << __TIME__ << std::endl; // log date and time of compilation, not runtime
    demonstrateInheritance();
    demonstrateMultipleInheritance();
    demonstratePolymorphism();
    return 0;
}
