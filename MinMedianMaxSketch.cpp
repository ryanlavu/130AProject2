#include "MinMedianMaxSketch.h"

	//private:
		//int size;
		//Heap minHeap;
		//Heap maxHeap;
		//T min, median, max;
		//bool found;
	//public:
		template <class T>
		MinMedianMaxSketch<T> :: MinMedianMaxSketch()
		{
			minHeap = new Heap(false);
			maxHeap = new Heap(true);
			size = 0;
		}

		template <class T>
		void MinMedianMaxSketch<T>::insert(int newElement)
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

		template <class T>
		void MinMedianMaxSketch<T>::remove(int goneElement)
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

		template <class T>
		T MinMedianMaxSketch<T>::get_median()
		{
			return median;
		}

		template <class T>
		T MinMedianMaxSketch<T>:: get_minimum()
		{
			return min;
		}

		template <class T>
		T MinMedianMaxSketch<T>::get_maximum()
		{
			return max;
		}

		template <class T>
		int MinMedianMaxSketch<T>::get_size()
		{
			return size;
		}

		template <class T>
		bool MinMedianMaxSketch<T>::search(T findElement)
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
