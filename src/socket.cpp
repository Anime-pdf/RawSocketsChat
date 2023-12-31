#include "socket.h"

#include <format>

Socket::Socket(const char* ip, const unsigned short port) {
    m_Invalid = !InitWinSock() || !InitSocket() || !ApplyAddress(ip, port) || !BindSocket();
}

bool Socket::IsInvalid() const {
    return m_Invalid;
}

bool Socket::InitWinSock() {
    WSADATA wsData;

    if (WSAStartup(MAKEWORD(2,2), &wsData) != 0) {
        Log("Error WinSock version initializaion #" + std::to_string(WSAGetLastError()));
        return false;
    }

    Log("WinSock initialization is OK");
    return true;
}

bool Socket::InitSocket() {
    m_Socket = socket(AF_INET, SOCK_STREAM, 0);

    if (m_Socket == INVALID_SOCKET) {
        Log("Error initialization socket #" + std::to_string(WSAGetLastError()));
        closesocket(m_Socket);
        WSACleanup();
        return false;
    }

    Log("Socket initialization is OK");
    return true;
}

bool Socket::ApplyAddress(const char* ip, const unsigned short port) {
    in_addr ip_to_num{};
    if (inet_pton(AF_INET, ip, &ip_to_num) <= 0) {
        Log("Error in IP translation to special numeric format.");
        closesocket(m_Socket);
        WSACleanup();
        return false;
    }

    ZeroMemory(&m_SockInfo, sizeof(m_SockInfo));

    m_SockInfo.sin_family = AF_INET;
    m_SockInfo.sin_addr = ip_to_num;
    m_SockInfo.sin_port = htons(port);

    Log("IP translation to special numeric format is OK");
    return true;
}

bool Socket::BindSocket() {
    if (bind(m_Socket, reinterpret_cast<sockaddr *>(&m_SockInfo), sizeof(m_SockInfo)) != 0) {
        Log("Error Socket binding to info. Error #" + std::to_string(WSAGetLastError()));
        closesocket(m_Socket);
        WSACleanup();
        return false;
    }

    Log("Binding socket to info is OK");
    return true;
}