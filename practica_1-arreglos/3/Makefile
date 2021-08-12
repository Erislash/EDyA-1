OBJS	= helpers.o arregloEnteros.o tests.o main.o
SOURCE	= helpers.c arregloEnteros.c tests.c main.c
HEADER	= typedefs.h helpers.h arregloEnteros.h tests.h
OUT	=
CC	 = gcc
# valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes -s ./a.out
FLAGS	 = -g -c -Wall -Wextra -Werror
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS)
	
helpers.o: helpers.c
	$(CC) $(FLAGS) helpers.c -std=c99

arregloEnteros.o: arregloEnteros.c
	$(CC) $(FLAGS) arregloEnteros.c -std=c99

tests.o: tests.c
	$(CC) $(FLAGS) tests.c -std=c99

main.o: main.c
	$(CC) $(FLAGS) main.c -std=c99

clean:
	rm -f $(OBJS)

run: $(OUT)
	./$(OUT)