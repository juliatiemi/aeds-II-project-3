CC = gcc
CFLAGS = -g -Wall
OBJ = main.o TADaluno.o TADbt.o TADsbb.o TADhash.o TADgenerico.o
DEPS = TADaluno.h TADbt.h TADsbb.h TADhash.h TADgenerico.h
EXEC = ./exec entrada.txt saida.txt 50 0
FLAGS = --leak-check=full --leak-resolution=high --show-reachable=yes --track-origins=yes

all: exec

exec: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clear:
	rm -f exec *.o

teste:
	$(EXEC)

val:
	valgrind $(FLAGS) $(EXEC)
