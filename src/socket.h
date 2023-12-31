#ifndef CHAT_SOCKET_H
#define CHAT_SOCKET_H

#include <iostream>
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

inline void Log(const std::string& str) {
    std::cout << str << std::endl;
}

class Socket {
protected:
    SOCKET m_Socket{};
    sockaddr_in m_SockInfo{};
public:
    Socket(const char* ip, unsigned short port);

    bool IsInvalid() const;
private:
    bool m_Invalid;

    static bool InitWinSock();
    bool InitSocket();
    bool ApplyAddress(const char* ip, unsigned short port);
    bool BindSocket();
};

#endif //CHAT_SOCKET_H
