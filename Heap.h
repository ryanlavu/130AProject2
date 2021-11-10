#ifndef HEAP_H
#define HEAP_H

#include <string>

using namespace std;

template<class T>
class Heap {

	private:

		bool max;
		vector<T> heap;
		int size;

	public:

		Heap(bool isMax);
		void insert(T element);
		void remove(T target);
		T getRoot();
		T extractRoot();
		T getMin();
		T getMax();
		T getSize();
		bool search(T target);
		void orderLast();

};

#endif
