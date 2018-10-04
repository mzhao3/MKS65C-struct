all: run
	./a.out

run: struct.o
	gcc struct.c
