CC=g++
FLAGS=-std=c++11 -c

debug: FLAGS += -g -O0
debug: lib

clean:
	rm -f *.a *.o

lib: food.o cupboard.o item.o fooddb.o recipe.o
	ar rcs libfood.a *.o

food.o:
	$(CC) $(FLAGS) food.cpp

cupboard.o:
	$(CC) $(FLAGS) cupboard.cpp

item.o:
	$(CC) $(FLAGS) item.cpp

fooddb.o:
	$(CC) $(FLAGS) fooddb.cpp

recipe.o:
	$(CC) $(FLAGS) recipe.cpp
