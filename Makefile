FLAGS=-Wall

all: test

test: main.c strtok.c strtok.h
	gcc ${FLAGS} main.c strtok.c -o test

.phony: clean
clean:
	rm test
