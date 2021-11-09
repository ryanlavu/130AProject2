#include MinMedianMaxSketch.h

	//private:
		//int size;
		//Heap minHeap;
		//Heap maxHeap;
		//int min, median, max;
		//bool found;
	//public:

		MinMedianMaxSketch()
		{
			minHeap = new Heap();
			maxHeap = new Heap();
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

		int get_median()
		{
			return median;
		}

		int get_minimum()
		{
			return min;
		}

		int get_maximum()
		{
			return max;
		}

		int get_size()
		{
			return size;
		}

		bool search(int findElement)
		{
			found = false;
			if(size == 0)
			{
				return false
			}
			else if(findElement > maxHeap.get_root())
			{
				found = minHeap.search(newElement);
			}
			else if(findElement > minHeap.get_root())
			{
				found = maxHeap.search(newElement);
			}
			return found;
		}