CC=g++
FLAGS=-std=c++11 -I ../lib -L ../lib
LD=-l food

debug: FLAGS += -g -O0
debug: all

all:
	$(CC) $(FLAGS) foodtracker.cpp $(LD) -o foodtracker

clean:
	rm -f foodtracker
