CFLAG= -g -Wall
gcc=g++ -std=c++11 $(CFLAG) 
default:server client

server: server.o
	$(gcc) -o server  server.cpp 

client: client.o
	$(gcc) -o client  client.cpp 

clean :
	rm -rf *.dSYM
	rm *.o client server 