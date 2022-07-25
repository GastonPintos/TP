CC = g++ -Wall -Werror -Wconversion
OBJS = main.o utiles.o

main: $(OBJS)
	$(CC) -o main $(OBJS)

main.o: main.cpp
	$(CC) -o main.o -c main.cpp

utiles.o : utiles.cpp utiles.h
	$(CC) -o utiles.o -c utiles.cpp

valgrind:
	valgrind --tool=memcheck --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./main

run: 
	./main