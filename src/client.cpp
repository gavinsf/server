#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main (int argc, char* argv[])
{
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9999);
    addr.sin_addr.s_addr = INADDR_ANY;

    connect(client_socket, (struct sockaddr*)&addr, sizeof(addr));

    const char* message = "Bello?";
    
    send(client_socket, message, strlen(message), 0);

    close(client_socket);   

    return 0;
}