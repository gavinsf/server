#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include "../include/TcpServer.h"
#include <sys/socket.h>
#include <vector>
#include <string>

#define MAX_BUFFER 2000


TcpServer::TcpServer(int port) : port(port), fd(-1) {}


TcpServer::~TcpServer() { if (fd != -1) close(fd); }


bool TcpServer::start()
{
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
    {
        std::cerr << "TcpServer failed to start\n";
        return false;
    }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(fd, (struct sockaddr*)&addr, sizeof(addr)) != 0)
    {
        std::cerr << "TcpServer failed to bind\n";
        return false;
    }

    if (listen(fd, 5) != 0)
    {
        std::cerr << "TcpServer failed to listen\n";
        return false;
    }
    return true;
}


int TcpServer::acceptConnections()
{
    int clientFd, bytes;
    while (true)
    {
        if ((clientFd = accept(fd, nullptr, nullptr)) == -1)
        {
            std::cerr << "TcpServer failed to accept connection\n";
        }
        else
        {
            std::cout << "Connection accepted\n";
            std::vector<std::string> buf(MAX_BUFFER);
            while ((bytes = recv(clientFd, buf.data(), buf.size(), 0)) > 0)
            {
                std::cout << "Printing: ";
                for (int i = 0; i < bytes; i++)
                    std::cout << buf[i];
            }

        }
    }
    return 0;
}