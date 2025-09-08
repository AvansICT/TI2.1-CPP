#include <iostream>
#include <bitset>
#include "bitdemo.hpp"

void demoBinair(void)
{
    // Demo binaire getallen in de code schrijven
    int x = 0b1010;  // binaire 1010 = decimaal 10
    int y = 0B1100;  // binaire 1100 = decimaal 12

    std::cout << "Decimaal: " << x << "\n";
    std::cout << "Decimaal: " << y << "\n";

    // Demo binaire output tonen
    unsigned int value = 42;

    std::cout << "Decimaal: " << value << "\n";
    std::cout << "Binair : " << std::bitset<8>(value) << "\n"; // 8 bits breed

    // Demo bitwise operatoren gebruiken
    unsigned int a = 0b1010; // 10
    unsigned int b = 0b0110; // 6

    std::cout << "a & b = " << std::bitset<4>(a & b) << "\n"; // 0010
    std::cout << "a | b = " << std::bitset<4>(a | b) << "\n"; // 1110
    std::cout << "a ^ b = " << std::bitset<4>(a ^ b) << "\n"; // 1100

    // Demo bit maskers
    value = 0b1010;  // 10
    // Check of bit 1 aan staat (mask = 0010)
    if (value & (1 << 1)) {
        std::cout << "Bit 1 is aan\n";
    }

    // Zet bit 0 aan (mask = 0001)
    value |= (1 << 0);

    std::cout << "Nieuwe waarde: " << value << " (" << std::bitset<4>(value) << ")\n";
}


// Flags als bitmaskers
const unsigned int READ     = 0b0001;   // 1
const unsigned int WRITE    = 0b0010;   // 2
const unsigned int EXECUTE  = 0b0100;   // 4
const unsigned int HIDDEN   = 0b1000;   // 8

int demoBitmask(void) 
{
    unsigned int permissions = 0;  // geen rechten

    // Rechten aanzetten
    permissions |= READ;    // 0001
    permissions |= WRITE;   // 0011

    std::cout << "Permissions: " << std::bitset<4>(permissions) << "\n";

    // Checken of EXECUTE aan staat
    if (permissions & EXECUTE) {
        std::cout << "Execute is allowed\n";
    }
    else {
        std::cout << "Execute is NOT allowed\n";
    }

    // EXECUTE aanzetten
    permissions |= EXECUTE;  // 0111

    // WRITE uitzetten
    permissions &= ~WRITE;   // 0101

    std::cout << "Updated permissions: " << std::bitset<4>(permissions) << "\n";

    return 0;
}

void demoHexadecimal(void)
{
    // Hexadecimale getallen schrijven  
    int decimaal = 42;  // decimaal
    int hex1 = 0x2A;    // hexadecimaal (42)
    int hex2 = 0X2A;    // idem

    std::cout << "decimaal: " << decimaal << "\n";
    std::cout << "hex1: " << hex1 << "\n";
    std::cout << "hex2: " << hex2 << "\n";

    //Hexadecimaal tonen met std::hex
    int x = 255;

    std::cout << "Decimaal: " << x << "\n";
    std::cout << "Hexadecimaal: " << std::hex << x << "\n";  // ff
    std::cout << "Hexadecimaal (met 0x): 0x" << std::hex << x << "\n";

    // Hex en bitwise operators
    unsigned int mask = 0x0F;   // 00001111 in binair
    unsigned int value = 0xAB;  // 10101011 in binair

    unsigned int result = value & mask;  // houdt alleen de onderste 4 bits
    std::cout << std::hex << result << "\n";
}