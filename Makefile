CC=gcc
CFLAGS=-I.

fileMake: MinMedianMaxSketch.o Heap.o main.o
	$(CC) -o fileMake MinMedianMaxSketch.o Heap.o main.o -lstdc++ -lm -ldl

clean:
	$(RM) fileMake MinMedianMaxSketch.o Heap.o main.o