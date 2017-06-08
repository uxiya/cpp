#include <sys/socket.h>
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <unistd.h>
class Conn {
public:
   int write(const void *data,int len);
   int read(void *data,int len);
   void close();
   sockaddr_in remote_addr;
   sockaddr_in local_addr;
   int remote_sockfd;
   int local_sockfd;
};