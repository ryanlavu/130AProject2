#ifndef MINMEDIANMAXSKETCH_H
#define MINMEDIANMAXSKETCH_H

#include "string"
#include "iostream"
#include "Heap.cpp"

using namepsace std;
template <class T>
class MinMedianMaxSketch
{
	private:

		int size;
		T median;
		T min;
		T max;
		bool found;
		Heap minHeap;
		Heap maxHeap;
	public:
		MinMedianMaxSketch()
		{
		}

		void insert(T newElement)
		{
		}

		void remove(T goneElement)
		{
		}

		T get_median()
		{}

		T get_minimum()
		{}

		T get_maximum()
		{
		}

		int get_size()
		{
		}

		bool search(T findElement)
		{}

}

#endif MINMEDIANMAXSKETCH_H