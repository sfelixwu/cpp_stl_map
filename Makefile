
# Makefile for s2023, ecs36b
# https://macappstore.org/libjson-rpc-cpp/
# https://github.com/cinemast/libjson-rpc-cpp
# for ecs36b openai, using JSON-CPP

CC = g++ -std=c++17

CFLAGS = -g

LDFLAGS = 	-L/opt/homebrew/lib/ -ljsoncpp

INC	=	ecs36b_Common.h ecs36b_Exception.h

# rules.
all: 	ecs36b_value_test map_test pair_test

#
#
# <target> : [... tab...] <dependency>
# [... tab ....] <action>

ecs36b_value_test.o:	ecs36b_value_test.cpp $(INC)
	$(CC) -c $(CFLAGS) ecs36b_value_test.cpp

map_test.o:	map_test.cpp
	$(CC) -c $(CFLAGS) map_test.cpp

pair_test.o:	pair_test.cpp
	$(CC) -c $(CFLAGS) pair_test.cpp

ecs36b_value_test:	ecs36b_value_test.o
	$(CC) -o ecs36b_value_test ecs36b_value_test.o $(LDFLAGS)

map_test:	map_test.o
	$(CC) -o map_test map_test.o

pair_test:	pair_test.o
	$(CC) -o pair_test pair_test.o

clean:
	rm -f *.o *~ core ecs36b_value_test map_test pair_test





