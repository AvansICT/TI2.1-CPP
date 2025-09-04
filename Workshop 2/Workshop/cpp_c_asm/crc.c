/* CRC calculations in C 
 * https://en.wikipedia.org/wiki/Cyclic_redundancy_check
 * Based on https://web.archive.org/web/20190108202303/www.hackersdelight.org/hdcodetxt/crc.c.txt 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4146) // disable warning about unary minus on unsigned type

#define BUFFER_SIZE  256

static unsigned int crc32b(const unsigned char* buf, int length);   // function prototype
static void logBuffer(const unsigned char* buf, unsigned int length);

void testcrc(void)
{
    unsigned char* buffer;
	buffer = (unsigned char*)malloc(BUFFER_SIZE + 1);// allocate memory for buffer
    if (buffer == NULL)
    {
        printf("Memory allocation failed\n");
        return;
	}
    else
    { 
        int crc;
        for (int i = 0; i < BUFFER_SIZE; i++)
        {
            buffer[i] = (unsigned char)(i & 0xFF); // fill buffer with some data
        };
        printf("%s input buffer:\n", __FUNCTION__);
		logBuffer(buffer, BUFFER_SIZE);

        crc = crc32b(buffer, BUFFER_SIZE);
		printf("CRC32 = 0x%08X\n", crc);

		free(buffer);// free allocated memory
		buffer = NULL; // Setting pointer NULL avoids dangling pointer issues.
    }
}

// CRC-32 algorithm (Ethernet, ZIP, etc.)
static unsigned int crc32b(const unsigned char* buf, int length) {
    int i, j;
    unsigned int byte, crc, mask;

    i = 0;
    crc = 0xFFFFFFFF;
    while (i < length) {
        byte = buf[i];            // Get next byte.
        crc = crc ^ byte;
        for (j = 7; j >= 0; j--) {    // Do eight times.
            mask = -(crc & 1);
            crc = (crc >> 1) ^ (0xEDB88320 & mask);
        }
        i = i + 1;
    }
    return ~crc;
}

// Log buffer content in hex format to console
static void logBuffer(const unsigned char* buf, unsigned int length)
{
    unsigned int idx;

    for (idx = 0; idx <= length; idx += 16)
    {
        // Log 16 bytes each line
        if (length - idx >= 16)
        {
            printf("0x%08x: %02x %02x %02x %02x %02x %02x %02x %02x  %02x %02x %02x %02x %02x %02x %02x %02x\n", idx, buf[idx], buf[idx + 1], buf[idx + 2], buf[idx + 3], buf[idx + 4], buf[idx + 5], buf[idx + 6], buf[idx + 7], buf[idx + 8], buf[idx + 9], buf[idx + 10], buf[idx + 11], buf[idx + 12], buf[idx + 13], buf[idx + 14], buf[idx + 15]);
        }
        else
        {
            // Log remaining bytes
            switch (length - idx)
            {
            default:
            case 0:
                break;
            case 1:
                printf("0x%08x: %02x\n", idx, buf[idx]);
                break;
            case 2:
                printf("0x%08x: %02x %02x\n", idx, buf[idx], buf[idx + 1]);
                break;
            case 3:
                printf("0x%08x: %02x %02x %02x\n", idx, buf[idx], buf[idx + 1], buf[idx + 2]);
                break;
            case 4:
                printf("0x%08x: %02x %02x %02x %02x\n", idx, buf[idx], buf[idx + 1], buf[idx + 2], buf[idx + 3]);
                break;
            case 5:
                printf("0x%08x: %02x %02x %02x %02x %02x\n", idx, buf[idx], buf[idx + 1], buf[idx + 2], buf[idx + 3], buf[idx + 4]);
                break;
            case 6:
                printf("0x%08x: %02x %02x %02x %02x %02x %02x\n", idx, buf[idx], buf[idx + 1], buf[idx + 2], buf[idx + 3], buf[idx + 4], buf[idx + 5]);
                break;
            case 7:
                printf("0x%08x: %02x %02x %02x %02x %02x %02x %02x\n", idx, buf[idx], buf[idx + 1], buf[idx + 2], buf[idx + 3], buf[idx + 4], buf[idx + 5], buf[idx + 6]);
                break;
            case 8:
                printf("0x%08x: %02x %02x %02x %02x %02x %02x %02x %02x\n", idx, buf[idx], buf[idx + 1], buf[idx + 2], buf[idx + 3], buf[idx + 4], buf[idx + 5], buf[idx + 6], buf[idx + 7]);
                break;
            case 9:
                printf("0x%08x: %02x %02x %02x %02x %02x %02x %02x %02x  %02x\n", idx, buf[idx], buf[idx + 1], buf[idx + 2], buf[idx + 3], buf[idx + 4], buf[idx + 5], buf[idx + 6], buf[idx + 7], buf[idx + 8]);
                break;
            case 10:
                printf("0x%08x: %02x %02x %02x %02x %02x %02x %02x %02x  %02x %02x\n", idx, buf[idx], buf[idx + 1], buf[idx + 2], buf[idx + 3], buf[idx + 4], buf[idx + 5], buf[idx + 6], buf[idx + 7], buf[idx + 8], buf[idx + 9]);
                break;
            case 11:
                printf("0x%08x: %02x %02x %02x %02x %02x %02x %02x %02x  %02x %02x %02x\n", idx, buf[idx], buf[idx + 1], buf[idx + 2], buf[idx + 3], buf[idx + 4], buf[idx + 5], buf[idx + 6], buf[idx + 7], buf[idx + 8], buf[idx + 9], buf[idx + 10]);
                break;
            case 12:
                printf("0x%08x: %02x %02x %02x %02x %02x %02x %02x %02x  %02x %02x %02x %02x\n", idx, buf[idx], buf[idx + 1], buf[idx + 2], buf[idx + 3], buf[idx + 4], buf[idx + 5], buf[idx + 6], buf[idx + 7], buf[idx + 8], buf[idx + 9], buf[idx + 10], buf[idx + 11]);
                break;
            case 13:
                printf("0x%08x: %02x %02x %02x %02x %02x %02x %02x %02x  %02x %02x %02x %02x %02x\n", idx, buf[idx], buf[idx + 1], buf[idx + 2], buf[idx + 3], buf[idx + 4], buf[idx + 5], buf[idx + 6], buf[idx + 7], buf[idx + 8], buf[idx + 9], buf[idx + 10], buf[idx + 11], buf[idx + 12]);
                break;
            case 14:
                printf("0x%08x: %02x %02x %02x %02x %02x %02x %02x %02x  %02x %02x %02x %02x %02x %02x\n", idx, buf[idx], buf[idx + 1], buf[idx + 2], buf[idx + 3], buf[idx + 4], buf[idx + 5], buf[idx + 6], buf[idx + 7], buf[idx + 8], buf[idx + 9], buf[idx + 10], buf[idx + 11], buf[idx + 12], buf[idx + 13]);
                break;
            case 15:
                printf("0x%08x: %02x %02x %02x %02x %02x %02x %02x %02x  %02x %02x %02x %02x %02x %02x %02x\n", idx, buf[idx], buf[idx + 1], buf[idx + 2], buf[idx + 3], buf[idx + 4], buf[idx + 5], buf[idx + 6], buf[idx + 7], buf[idx + 8], buf[idx + 9], buf[idx + 10], buf[idx + 11], buf[idx + 12], buf[idx + 13], buf[idx + 14]);
                break;
            }
        }
    }
}
