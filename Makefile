CC=gcc
CFLAGS=-I.

SRC= main.c motif1.c motif2.c tabstr.c utils.c haskcode.c tableau.c
OBJ=$(SRC:.c=.o)
EXEC=main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean

