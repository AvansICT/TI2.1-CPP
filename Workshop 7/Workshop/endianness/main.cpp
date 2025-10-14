#include <iostream>
#include <cstdint>


void checkEndianness(void)
{
    uint32_t num = 0x12345678;
    uint8_t* ptr = reinterpret_cast<uint8_t*>(&num);

    std::cout << "Memory bytes: ";
    for (int i = 0; i < 4; ++i)
        std::cout << std::hex << static_cast<int>(ptr[i]) << " ";
    std::cout << std::dec << "\n";

    if (ptr[0] == 0x78)
        std::cout << "System is little-endian\n";
    else if (ptr[0] == 0x12)
        std::cout << "System is big-endian\n";
    else
        std::cout << "Unknown endianness\n";
}

void checkEndiannessModernWay(void) //Modern C++ Way (C++20)
{
    if constexpr (std::endian::native == std::endian::little)
        std::cout << "Little-endian\n";
    else if constexpr (std::endian::native == std::endian::big)
        std::cout << "Big-endian\n";
    else
        std::cout << "Mixed-endian (rare)\n";
}

int main() {
    std::cout << "endianess!\n";
    std::cout << __DATE__ << " " << __TIME__ << std::endl; // log date and time of compilation, not runtime
    checkEndianness();
	checkEndiannessModernWay();
}
