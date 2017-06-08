#include <sys/socket.h>
#include <netinet/in.h>  
#include "conn.h"

class Socket{
public:
    Socket();
    ~Socket();
    bool setAddress(const char *addr,const int port);
    Conn * connect();
    bool listen();
    Conn * accept();
    void close();
protected:
    sockaddr_in _address;
    int _sockfd; 
    int sin_size;
};