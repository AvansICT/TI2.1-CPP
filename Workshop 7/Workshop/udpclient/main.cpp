#include <iostream>
#include <string>
#include "log.hpp"

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define SOCKET int
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#endif

void closeSocket(SOCKET sock) {
#ifdef _WIN32
    closesocket(sock);
#else
    close(sock);
#endif
}
#define PORT 8080
#define IP_ADDRESS "127.0.0.1"  //localhost loopback address
int main() {
    std::cout << "UDP CLient!\n";
    std::cout << __DATE__ << " " << __TIME__ << std::endl; // log date and time of compilation, not runtime
    LogOperatingSystem();
    LogCompiler();
#ifdef _WIN32
    WSADATA wsaData;
    (void)WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif

    SOCKET clientSock = socket(AF_INET, SOCK_DGRAM, 0);
    if (clientSock == INVALID_SOCKET) {
        std::cerr << "Cannot create socket\n";
        return 1;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, IP_ADDRESS, &serverAddr.sin_addr);

    while (true) {
        std::string msg;
        std::cout << "Enter message (or 'quit'): ";
        std::getline(std::cin, msg);
        if (msg == "quit") break;

        sendto(clientSock, msg.c_str(), (int)msg.size(), 0,
            (sockaddr*)&serverAddr, sizeof(serverAddr));

        char buffer[1024];
        sockaddr_in fromAddr{};
        socklen_t fromLen = sizeof(fromAddr);
        int bytes = recvfrom(clientSock, buffer, sizeof(buffer) - 1, 0,
            (sockaddr*)&fromAddr, &fromLen);
        if (bytes > 0) {
            buffer[bytes] = '\0';
            std::cout << "Server says: " << buffer << "\n";
        }
    }

    closeSocket(clientSock);

#ifdef _WIN32
    WSACleanup();
#endif

    return 0;
}
