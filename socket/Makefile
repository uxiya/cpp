CFLAG= -g -Wall
gcc=g++ -std=c++11 $(CFLAG) 

default:server client

server:
	$(gcc) -o server server.cpp  lib/net/tcpsocket.cpp lib/net/conn.cpp
client:
	$(gcc) -o client  client.cpp lib/net/tcpsocket.cpp lib/net/conn.cpp
clean :
	rm -rf *.dSYM
	rm -r *.o *.a client server 
