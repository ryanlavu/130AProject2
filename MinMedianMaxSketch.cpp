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
		Heap<T> * minHeap;
		Heap<T> * maxHeap;
	
		MinMedianMaxSketch()
		{
			minHeap = new Heap<T>(false);
			maxHeap = new Heap<T>(true);
			size = 0;
		}

		void insert(int newElement)
		{
			if(size == 0)
			{
				maxHeap->insert(newElement);
				min = newElement;
				max = newElement;
				median = newElement;
			}
			else if(newElement > maxHeap->getRoot())
			{
				minHeap->insert(newElement);
				max = minHeap->getMax();
			}
			else if(newElement > minHeap->getRoot())
			{
				maxHeap->insert(newElement);
				min = maxHeap->getMin();
			}
			size++;

			if(minHeap->getSize() - maxHeap->getSize() > 1)
			{
				maxHeap->insert(minHeap->extractRoot());
				median = minHeap->getRoot();
			}
			else if(minHeap->getSize() - maxHeap->getSize() < -1 )
			{
				minHeap->insert(maxHeap->extractRoot());
				median = maxHeap->getRoot();
			}
			else if(minHeap->getSize() == maxHeap->getSize())
			{
				median = maxHeap->getRoot();
			}
		}

		void remove(int goneElement)
		{
			if(size == 0)
			{
				//Does nothing
			}
			else if(goneElement > maxHeap->getRoot())
			{
				minHeap->remove(goneElement);
				max = minHeap->getMax();
			}
			else if(goneElement > minHeap->getRoot())
			{
				maxHeap->remove(goneElement);
				min = maxHeap->getMin();
			}
			size--;

			if(minHeap->getSize() - maxHeap->getSize() > 1)
			{
				maxHeap->insert(minHeap->extractRoot());
				median = minHeap->getRoot();
			}
			else if(minHeap->getSize() - maxHeap->getSize() < -1 )
			{
				minHeap->insert(maxHeap->extractRoot());
				median = maxHeap->getRoot();
			}
			else if(minHeap->getSize() == maxHeap->getSize())
			{
				median = maxHeap->getRoot();
			}
		}

		T get_median()
		{
			return median;
		}

		T get_minimum()
		{
			return min;
		}

		T get_maximum()
		{
			return max;
		}

		int get_size()
		{
			return size;
		}

		bool search(T findElement)
		{
			found = false;
			if(size == 0)
			{
				return false;
			}
			else if(findElement > maxHeap->get_root())
			{
				found = minHeap->search(findElement);
			}
			else if(findElement > minHeap->get_root())
			{
				found = maxHeap->search(findElement);
			}
			return found;
		}

};
