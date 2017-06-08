#include <stdio.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <string.h>
#include <unistd.h>

#include "lib/net/tcpsocket.h"
  
int main(int argc, char *argv[])  
{  
    Socket socket;
    socket.setAddress("0.0.0.0",8000);
    socket.listen();

    char buf[BUFSIZ];  //数据传送的缓冲区  
    Conn *conn;
    conn=socket.accept();
    printf("accept client %s\n",inet_ntoa(conn->remote_addr.sin_addr));  
    conn->write("Welcome to my server\n",21);
      
    int len;
    while((len=conn->read(buf,BUFSIZ))>0){  
        buf[len]='\0';  
        printf("%s\n",buf);  
        
        if(conn->write(buf,len)<0){  
            perror("write error");  
            return 1;  
        }  
    }  
    conn->close();
    socket.close();
    return 0;  
}  