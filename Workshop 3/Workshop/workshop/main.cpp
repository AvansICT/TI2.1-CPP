// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "robot.hpp"
#include "log.hpp"

struct data {
    int i;
    bool b;
};

// Notatie: pointer naar een struct gebruiken
void demo1(void) {
    struct data s;
    struct data* p;
    p = &s;
    s.i = 42;
    s.b = true;

    std::cout << s.i << " " << (s.b ? 1 : 0) << '\n'; // 42 1
    p->i = 43;
    std::cout << s.i << " " << (s.b ? 1 : 0) << '\n'; // 43 1
    p->b = false;
    std::cout << s.i << " " << (s.b ? 1 : 0) << '\n'; // 43 0
}

void changeCallByValue(int x) {
    x = 2; // verandert alleen de kopie
}

void changeCallByReference(int& x) {
    x = 3; // werkt direct op 'a'
}

void changeCallByValuePtr(int* p) {
    *p = 4; // via de pointer veranderen we de originele variabele
}

void changePointer(int*& p) {
    static int other = 123;
    p = &other; // laat pointer naar iets anders wijzen
}

// call by reference / call by value
void demo2(void) {
    int a = 1;
    int* ptr = &a;
    changeCallByValue(a);       // Call by Value
    cout << a << endl;          // output: 1
    changeCallByReference(a);   // Call by Reference (voorkeur)
    cout << a << endl;          // output: 3
    changeCallByValuePtr(&a);   // Pointer doorgeven (Call by Value met pointer)
    cout << a << endl;          // output: 4
    changePointer(ptr);         // Pointer by Reference (Call by Reference met pointer)
    cout << *ptr << endl;       // output: 123
}

void renameCallByValue(Robot r) {
    r.name = "Copied";
}

void renameCallByReference(Robot& r) {
    r.name = "Beta";
}

void renameByPointer(Robot* r) {
    r->name = "Gamma";
}

void pointToNewRobot(Robot*& r) {
    static Robot newBot("Delta");
    r = &newBot; // pointer wijst nu naar een ander object
}
// call by reference / call by value
void demo3(void) {
    Robot a("Alpha");
    Robot* ptr = &a;
    renameCallByValue(a);   // Call by Value kopie van object
    cout << a.name << endl; // output: Alpha
    renameCallByReference(a);
    cout << a.name << endl;  // Output: Beta
    renameByPointer(ptr);
    cout << a.name << endl;  // Output: Gamma
    pointToNewRobot(ptr);
    cout << ptr->name << endl;  // Output: Delta
}

union ByteBool {
    unsigned char byte;
    bool flag;
};

struct ByteWithFlag {
    unsigned char value : 7;  // 7 bits voor een getal (0–127)
    bool flag : 1;            // 1 bit voor een boolean
};
// union / bitfields
void demo4(void) {
    // union
    ByteBool test;
    test.byte = 255;
    std::cout << "byte: " << (int)test.byte << " bool: " << test.flag << std::endl;
    test.flag = false;
    std::cout << "byte: " << (int)test.byte << " bool: " << test.flag << std::endl;
 
    ByteWithFlag b{ 42, true };   // 42 + flag = true
    cout << "Value: " << (int)b.value << ", Flag: " << b.flag << endl;

    b.value = 100;
    b.flag = false;
    cout << "Value: " << (int)b.value << ", Flag: " << b.flag << endl;
}

int main()
{
    std::cout << "Workshop 3!\n";
    std::cout << __DATE__ << " " << __TIME__ << std::endl; // log date and time of compilation, not runtime
    demo1();
    demo2();
    demo3();
    demo4();
    return 0;
}
