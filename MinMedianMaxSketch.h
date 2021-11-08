#ifndef MINMEDIANMAXSKETCH_H
#define MINMEDIANMAXSKETCH_H

#include "string"
#include "iostream"

using namepsace std;

class MinMedianMaxSketch
{
	private:
		int size;
		int median;
		int min;
		int max;
		Heap minHeap;
		Heap maxHeap;
	public:
		MinMedianMaxSketch()
		{
		}

		void insert(int newElement)
		{
		}

		void remove(int goneElement)
		{
		}

		int get_median()
		{}

		int get_minimum()
		{}

		int get_maximum()
		{
		}

		int get_size()
		{
		}

		bool search(int findElement)
		{}

}

#endif MINMEDIANMAXSKETCH_H