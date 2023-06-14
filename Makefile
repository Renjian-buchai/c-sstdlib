CC=g++
DEF= 
INC= -I.
LIN= 

all: com run 

check: com 

com: test.cpp
	$(CC) -otest.exe -Wall test.cpp $(DEF) $(INC) $(LIN)

run: 
	./test.exe