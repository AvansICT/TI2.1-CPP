#include "student.hpp"
#include "customer.hpp"
#include "patient.hpp"
#include <ctime>
#include <utility> // std::move
// https://en.cppreference.com/w/cpp/language/rule_of_three.html

int main() {
    std::cout << "ThreeFiveZero!\n";
    std::cout << __DATE__ << " " << __TIME__ << std::endl; // log date and time of compilation, not runtime

    srand((unsigned)time(nullptr));

    std::cout << "\n--- Constructor ---\n";
    Student s("Alice", 20, "Computer Science", 5);
    Customer c("Bob", 45, "CUST123", 4);
    Patient p("Charlie", 60, "Diabetes", 6);

    //--- Rule of Zero: student ---
    // No explicit debug output, because all special member functions are compiler 
    // generated.The code still works correctly because std::string and std::vector handle 
    // their own memory.

    std::cout << "\n--- Rule of Three: Customer ---\n";
    std::cout << "\n1. Destructor will run at program end\n";
    std::cout << "\n2. Copy constructor\n";
    Customer c2 = c;   // calls copy constructor
    std::cout << "\n3. Copy assignment\n";
    Customer c3("Temp", 30, "TMP", 2);
    c3 = c;            // calls copy assignment

    std::cout << "\n--- Rule of Five: Patient ---\n";
    std::cout << "\n1. Destructor will run at program end\n";
    std::cout << "\n2. Copy constructor\n";
    Patient p2 = p;    // calls copy constructor
    std::cout << "\n3. Copy assignment\n";
    Patient p3("Tmp", 50, "Test", 2);
    p3 = p;            // calls copy assignment
    std::cout << "\n4. Move constructor\n";
    Patient p4 = std::move(p2); // calls move constructor
    std::cout << "\n5. Move assignment\n";
    Patient p5("Tmp2", 40, "Temp", 3);
    p5 = std::move(p3);         // calls move assignment

    std::cout << "\n--- Program End: Destructors will be called automatically ---\n";
}
