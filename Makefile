mainFile: MinMedianMaxSketch.o Heap.o main.o
	gcc -o mainFile MinMedianMaxSketch.o Heap.o main.o -lstdc++ -lm -ldl

clean:
	$(RM) mainFile MinMedianMaxSketch.o Heap.o main.o
