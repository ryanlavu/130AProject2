#ifndef HEAP_H
#define HEAP_H

#include <string>

using namespace std;

template<class T>
class Heap {

	public:
		Heap(bool isMax);
		void insert(T element);
		void remove(T target);
		T getRoot();
		T extractRoot();
		T getMin();
		T getMax();
		int getSize(){return size;}
		bool search(T target);
		void orderLast();

		void setSize(int setTo){size = setTo;}
		
	private:
		bool max;
		vector<T> heap;
		int size;
};

#endif
