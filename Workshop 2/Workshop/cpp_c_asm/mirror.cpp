#include <iostream>
#include <iomanip>

#define BUFFER_SIZE  256

static void logBuffer(const unsigned char* buf, unsigned int length);

void testMirror(void)
{
    int size = BUFFER_SIZE;
    int i;
    unsigned char* buffer = new unsigned char[size];   // allocate on heap
	
    if (!buffer)
    {
        std::cout << "Memory allocation failed\n" << std::endl ;
        return;
    }
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        buffer[i] = i; // fill buffer with some data
    }
	
	std::cout << __FUNCTION__ << " input buffer:\n";
    logBuffer(buffer, BUFFER_SIZE);
    for (i = 0; i < BUFFER_SIZE; i++)
    {
		// mirror byte
        buffer[i] = 255 - i;
    }
    std::cout << __FUNCTION__ << " output buffer:\n";
    logBuffer(buffer, BUFFER_SIZE);
	delete[] buffer; // free allocated memory
	buffer = nullptr;// Setting pointer nullptr avoids dangling pointer issues.
}

static void logBuffer(const unsigned char* buf, unsigned int length)
{
    const unsigned int bytesPerLine = 16;

    for (unsigned int idx = 0; idx < length; idx += bytesPerLine)
    {
        // Print the address/offset
        std::cout << "0x"
            << std::setw(8) << std::setfill('0') << std::hex << idx
            << ": ";

        // Print up to 16 bytes in hex
        for (unsigned int j = 0; j < bytesPerLine; ++j)
        {
            if (idx + j < length)
            {
                std::cout << std::setw(2) << std::setfill('0')
                    << std::hex << static_cast<int>(buf[idx + j]) << " ";
            }
            else
            {
                // Print spaces for alignment
                std::cout << "   ";
            }

            // Add extra space in the middle (like your printf version)
            if (j == 7) std::cout << " ";
        }

        std::cout << std::dec << "\n"; // reset to decimal at end of line
    }
}