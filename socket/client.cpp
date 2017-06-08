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

    Conn *conn;
    Socket socket;
    socket.setAddress("127.0.0.1",8000);
    conn=socket.connect();
    if (conn->remote_sockfd<=0){
        return 1;       
    }
    printf("connected to server\n");  
    int len;
    char buf[BUFSIZ]; 
    len=conn->read(buf,BUFSIZ);
    buf[len]='\0';  
    printf("%s",buf); //打印服务器端信息  
      
    while(1)  
    {  
        printf("Enter string to send:");  
        scanf("%s",buf);  
        if(!strcmp(buf,"quit"))  
            break;  
        conn->write(buf,len);
        len=conn->read(buf,BUFSIZ);
        printf("received:%s\n",buf);  
    }  
      
    conn->close();      
    return 0;  
}  