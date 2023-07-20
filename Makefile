CC=g++
DEF= 
INC= -I.
LIN= 

all: com run 

check: com 

com: test.cpp
	$(CC) -otest.exe -Wall -Wextra test.cpp $(DEF) $(INC) $(LIN) -std=c++20

run: 
	./test.exe