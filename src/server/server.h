#ifndef CHAT_SERVER_H
#define CHAT_SERVER_H
#include <thread>
#include <vector>

#include "../socket.h"

class Server : Socket {
    std::thread* m_ListeningThread;
    std::vector<SOCKET> m_vAcceptedClients;
    std::vector<std::thread> m_vConnectionThreads;
public:
    Server(const char* ip, unsigned short port) : Socket(ip, port) {}

    bool StartListen();

};

#endif //CHAT_SERVER_H
