#ifndef HEAP_H
#define HEAP_H

#include <string>

using namespace std;

class Heap {

	private:

		int * heapArray;
		int size;

	public:

		Heap(bool isMax);
		void insert(int element);
		void remove(int target);
		int getRoot();
		int extractRoot();
		int getMin();
		int getMax();
		int getSize();
		bool search;
		void swapLast(int index);

};

#endif
