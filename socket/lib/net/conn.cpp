#include "conn.h"

int Conn::read(void *data,int len){
    len=recv(remote_sockfd,data,len,0);
    return len;
}

int Conn::write(const void *data,int len){
    len=send(remote_sockfd,data,len,0); 
    return len;
}


void Conn::close(){
    ::close(remote_sockfd);
}