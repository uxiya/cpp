#include "tcpsocket.h"

Socket::Socket(){
   _address.sin_family = AF_INET;
   sin_size=sizeof(struct sockaddr_in);  
}


Socket::~Socket(){
    close();
}

bool Socket::setAddress (const char *addr,const int port){
   _address.sin_addr.s_addr=inet_addr(addr);
   _address.sin_port = htons(port); 
    return true;
}

Conn * Socket::connect(){
    Conn *conn = new Conn;
    conn->remote_addr = _address;

    if((conn->remote_sockfd=socket(PF_INET,SOCK_STREAM,0))<0){
        return conn;
    }
    if(::connect(conn->remote_sockfd,(struct sockaddr *)&conn->remote_addr,sizeof(struct sockaddr))<0){
       return conn; 
    }
    return conn;
}

bool Socket::listen(){
    if((_sockfd=socket(PF_INET,SOCK_STREAM,0))<0){    
        return false;  
    }  
    if(bind(_sockfd,(struct sockaddr *)&_address,sizeof(struct sockaddr))<0){
        return false;
    } 
    if(::listen(_sockfd,9999)<0){
        return false;
    }  
    return true;
}

Conn * Socket::accept(){
    Conn *conn = new Conn;
    conn->local_addr = _address;
    conn->local_sockfd = _sockfd;
    conn->remote_sockfd=::accept(_sockfd,(struct sockaddr *)&conn->remote_addr,(socklen_t *)&sin_size);
    return conn;  
}

void Socket::close(){
    ::close(_sockfd);    
}