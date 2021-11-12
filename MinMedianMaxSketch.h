#ifndef MINMEDIANMAXSKETCH_H
#define MINMEDIANMAXSKETCH_H

#include "string"
#include "iostream"
#include "Heap.cpp"

template <class T>
class MinMedianMaxSketch
{
	public:

		int size;
		T median;
		T min;
		T max;
		bool found;
		Heap minHeap;
		Heap maxHeap;
	
		MinMedianMaxSketch();

		void insert(T newElement);

		void remove(T goneElement);

		T get_median();

		T get_minimum();

		T get_maximum();

		int get_size();

		bool search(T findElement);

};

#endif
