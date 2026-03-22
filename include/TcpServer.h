#pragma once

class TcpServer {
private:
    int port;
    int fd;

public:
    TcpServer(int port);
    ~TcpServer();
    
    bool start();
    int acceptConnections();
};

