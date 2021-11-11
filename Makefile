mainFile: MinMedianMaxSketch.o Heap.o main.o
	gcc -o project1b MinMedianMaxSketch.o Heap.o main.o -lstdc++ -lm -ldl

clean:
	$(RM) project1b MinMedianMaxSketch.o Heap.o main.o