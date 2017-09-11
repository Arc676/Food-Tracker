CC=g++
FLAGS=-std=c++11 -c

clean:
	rm *.a *.o

lib: food.o cupboard.o item.o fooddb.o
	ar rcs libfood.a *.o

food.o:
	$(CC) $(FLAGS) food.cpp

cupboard.o:
	$(CC) $(FLAGS) cupboard.cpp

item.o:
	$(CC) $(FLAGS) item.cpp

fooddb.o:
	$(CC) $(FLAGS) fooddb.cpp
