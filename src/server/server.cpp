#include "server.h"

#include <iostream>
#include <string>

bool Server::StartListen() {
    m_ListeningThread = new std::thread([this] {
        if (listen(m_Socket, SOMAXCONN_HINT(4) != 0)) {
            Log("Can't start to listen to. Error #" + std::to_string(WSAGetLastError()));
            closesocket(m_Socket);
            WSACleanup();
            return false;
        }

        Log("Listening...");

        sockaddr_in clientInfo;
        ZeroMemory(&clientInfo, sizeof(clientInfo));

        int clientInfo_size = sizeof(clientInfo);

        SOCKET ClientConn = accept(m_Socket, (sockaddr*)&clientInfo, &clientInfo_size);

        if (ClientConn == INVALID_SOCKET) {
            Log("Client detected, but can't connect to a client. Error #" + std::to_string(WSAGetLastError()));
            closesocket(m_Socket);
            closesocket(ClientConn);
            WSACleanup();
            return false;
        }
        m_vAcceptedClients.push_back(ClientConn);

        Log("Connection to a client established successfully");
        return true;
    });
    return false;
}
