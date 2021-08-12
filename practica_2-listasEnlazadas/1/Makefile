OBJS	= helpers.o slist.o tests.o main.o
SOURCE	= helpers.c slist.c tests.o main.c
HEADER	= helpers.h slist.h tests.o
OUT	=
CC	 = gcc
FLAGS	 = -g -c -Wall -Wextra -Werror
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS)
	
helpers.o: helpers.c
	$(CC) $(FLAGS) helpers.c -std=c99

slist.o: slist.c
	$(CC) $(FLAGS) slist.c -std=c99

tests.o: tests.c
	$(CC) $(FLAGS) tests.c -std=c99

main.o: main.c
	$(CC) $(FLAGS) main.c -std=c99

clean:
	rm -f $(OBJS)

run: $(OUT)
	./$(OUT)