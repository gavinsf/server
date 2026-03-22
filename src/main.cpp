#include "../include/TcpServer.h"

int main (int argc, char* argv[])
{
    TcpServer server(9999);
    if (!server.start()) return -1;
    if (server.acceptConnections() != 0) return -1;

    return 0;
}
