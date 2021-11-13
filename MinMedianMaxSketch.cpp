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
			//cout << "minHeap is a " << minHeap->getIsMax() << " maxHeap" << endl;
			maxHeap = new Heap<T>(true);
			//cout << "maxHeap is a " << maxHeap->getIsMax() << " maxHeap" << endl;
			size = 0;
		}

		void insert(T newElement)
		{
			//if(newElement == 252)
				//cout << "INSERTING THIS ELEMENT = " << newElement << endl;	
			if(size == 0)
			{
				maxHeap->insert(newElement);
				//min = newElement;
				//max = newElement;
				//median = newElement;
			}
			else if(newElement > maxHeap->getRoot())
			{
				minHeap->insert(newElement);
				//max = minHeap->getMax();
			}
			else if(newElement < minHeap->getRoot())	
			{
				maxHeap->insert(newElement);
				//min = maxHeap->getMin();
			}
			size++;

			/*if(newElement ==252)
			{
				cout << "IS 252 IN MAXHEAP? " << maxHeap->search(252) << endl;
				cout << "IS 252 IN MINHEAP? " << minHeap->search(252) << endl;
			}*/

			if(minHeap->getSize() - maxHeap->getSize() > 1)
			{
				maxHeap->insert(minHeap->extractRoot());
				//median = minHeap->getRoot();
			}
			else if(minHeap->getSize() - maxHeap->getSize() < -1 )
			{
				minHeap->insert(maxHeap->extractRoot());
				//median = maxHeap->getRoot();
			}
			else if(minHeap->getSize() == maxHeap->getSize())
			{
				//median = maxHeap->getRoot();
			}

			/*if(newElement ==252)
			{
				cout << "IS 252 IN MAXHEAP? " << maxHeap->search(252) << endl;
				cout << "IS 252 IN MINHEAP? " << minHeap->search(252) << endl;
			}*/
		}

		void remove(T goneElement)
		{
			if(size == 0)
			{
				//Does nothing
			}
			else if(goneElement > maxHeap->getRoot())
			{
				minHeap->remove(goneElement);
				//max = minHeap->getMax();
			}
			else if(goneElement < minHeap->getRoot())
			{
				maxHeap->remove(goneElement);
				//min = maxHeap->getMin();
			}
			size--;

			if(minHeap->getSize() - maxHeap->getSize() > 1)
			{
				maxHeap->insert(minHeap->extractRoot());
				//median = minHeap->getRoot();
			}
			else if(minHeap->getSize() - maxHeap->getSize() < -1 )
			{
				minHeap->insert(maxHeap->extractRoot());
				//median = maxHeap->getRoot();
			}
			else if(minHeap->getSize() == maxHeap->getSize())
			{
				//median = maxHeap->getRoot();
			}
		}

		T get_median()
		{
			if(minHeap->getSize() - maxHeap->getSize() > 0)
				return minHeap->getRoot();
			else if(maxHeap->getSize() - minHeap->getSize() > 0)
				return maxHeap->getRoot();
			else
				return maxHeap->getRoot();
		}


		T get_minimum()
		{
			return maxHeap->getMin();
		}

		T get_maximum()
		{
			return minHeap->getMax();
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

		void printMaxHeap()
		{
			maxHeap->printOut();
		}
		void printMinHeap()
		{
			minHeap->printOut();
		}

};
