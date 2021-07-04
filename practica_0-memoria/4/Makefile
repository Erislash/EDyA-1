OBJS	= helpers.o main.o
SOURCE	= helpers.c main.c
HEADER	= helpers.h
OUT	=
CC	 = gcc
FLAGS	 = -g -c -Wall -Wextra -Werror
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS)
	
helpers.o: helpers.c
	$(CC) $(FLAGS) helpers.c -std=c99

main.o: main.c
	$(CC) $(FLAGS) main.c -std=c99

clean:
	rm -f $(OBJS)

run: $(OUT)
	./$(OUT)