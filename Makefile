flags=-O2 -Wall -std=c2x
ldflags=-lbu

.PHONY: all clean

all: clean hyperbird

hyperbird: hyperbird.o
	cc $(flags) $^ -o $@ $(ldflags)

hyperbird.o: hyperbird.c hyperbird.h
	cc $(flags) -c $<

clean:
	rm -f *.o hyperbird