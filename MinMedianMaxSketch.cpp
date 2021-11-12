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
	
		MinMedianMaxSketch()
		{
			minHeap = new Heap(false);
			maxHeap = new Heap(true);
			size = 0;
		}

		void insert(int newElement)
		{
			if(size == 0)
			{
				maxHeap.insert(newElement);
				min = newElement;
				max = newElement;
				median = newElement;
			}
			else if(newElement > maxHeap.get_root())
			{
				minHeap.insert(newElement);
				max = minHeap.get_max();
			}
			else if(newElement > minHeap.get_root())
			{
				maxHeap.insert(newElement);
				min = maxHeap.get_min();
			}
			size++;

			if(minHeap.get_size() - maxHeap.getSize() > 1)
			{
				maxHeap.insert(minHeap.extract_root());
				median = minHeap.get_root();
			}
			else if(minHeap.get_size() - maxHeap.getSize() < -1 )
			{
				minHeap.insert(maxHeap.extract_root());
				median = maxHeap.get_root();
			}
			else if(minHeap.get_size() == maxHeap.getSize())
			{
				median = maxHeap.get_root();
			}
		}

		void remove(int goneElement)
		{
			if(size == 0)
			{
				//Does nothing
			}
			else if(newElement > maxHeap.get_root())
			{
				minHeap.remove(newElement);
				max = minHeap.get_max();
			}
			else if(newElement > minHeap.get_root())
			{
				maxHeap.remove(newElement);
				min = maxHeap.get_min();
			}
			size--;

			if(minHeap.get_size() - maxHeap.getSize() > 1)
			{
				maxHeap.insert(minHeap.extract_root());
				median = minHeap.get_root();
			}
			else if(minHeap.get_size() - maxHeap.getSize() < -1 )
			{
				minHeap.insert(maxHeap.extract_root());
				median = maxHeap.get_root();
			}
			else if(minHeap.get_size() == maxHeap.getSize())
			{
				median = maxHeap.get_root();
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
			else if(findElement > maxHeap.get_root())
			{
				found = minHeap.search(findElement);
			}
			else if(findElement > minHeap.get_root())
			{
				found = maxHeap.search(findElement);
			}
			return found;
		}

};