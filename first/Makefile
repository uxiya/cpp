CFLAG= -g -Wall
gcc=g++ -std=c++11 $(CFLAG) 
default:main

bird.o: bird.cpp
	$(gcc) -c bird.cpp

main: bird.o
	$(gcc) -o main  bird.o main.cpp 

clean :
	rm main
	rm bird.o
	rm -rf *dSYM
