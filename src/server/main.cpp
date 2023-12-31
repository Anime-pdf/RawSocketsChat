#include <format>

#include "../socket.h"

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Log("server");

    Log("s1:");
    Socket s1("127.0.0.1", 2011);
    Log("s2:");
    Socket s2("127.0.0.1", 2012);
    Log("s3:");
    Socket s3("127.0.0.1", 2012);
    Log("s4:");
    Socket s4("1270.0.1", 20112);

    Log(std::format("IsInvalid: s1: {}, s2: {}, s3: {}, s4: {}",
        s1.IsInvalid(),
        s2.IsInvalid(),
        s3.IsInvalid(),
        s4.IsInvalid()));

    return 0;
}
