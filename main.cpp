#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "Heap.h"
#include "Heap.cpp"
#include "MinMedianMaxSketch.h"
#include "MinMedianMaxSketch.cpp"

using namespace std;

int main(int argc, char *argv[]) {
		string heapOrSketch = argv[1]


		if(heapOrSketch == "heap")
		{
			Heap<int> maxHeap = new Heap(true);
			Heap<int> minHeap = new Heap(false);

			//insert into heaps
			ifstream insertFile(argv[2]);
			while(getline(insertFile, query))
			{
				if(query.empty())
					break;
				maxHeap.insert(query);
				minHeap.insert(query);
			}	
			insertFile.close();


			//delete from heaps
			ifstream deleteFile(argv[3]);
			while(getline(deleteFile, query))
			{
				if(query.empty())
					break;

				if(maxHeap.getRoot() == query)
				{
					maxHeap.extractRoot();
				}
				else
				{
					maxHeap.remove(query);
				}
				if(minHeap.getRoot() == query)
				{
					minHeap.extractRoot();
				}
				else
				{
					minHeap.remove(query);
				}
			}	
			deleteFile.close();

			//report stats
			cout << "Min Heap:\n" << "Size = " << minHeap.getSize() << "\nMin = " << minHeap.getRoot() << "\nMax = " << minHeap.getMax() << endl;
			cout << "Max Heap:\n" << "Size = " << maxHeap.getSize() << "\nMin = " << maxHeap.getRoot() << "\nMax = " << maxHeap.getMax() << endl;
		}
		else
		{
			MinMedianMaxSketch<int> sketch = new MinMedianMaxSketch();

			//insert into sketch
			ifstream insertFile(argv[2]);
			while(getline(insertFile, query))
			{
				if(query.empty())
					break;
				sketch.insert(query);
			}	
			insertFile.close();

			//delete from sketch
			ifstream deleteFile(argv[3]);
			while(getline(deleteFile, query))
			{
				if(query.empty())
					break;
				sketch.remove(query);
			}	
			deleteFile.close();

			//report stats
			cout << "MinMedianMaxSketch:\n" << "Size = " << sketch.get_size() << "\nMin = " << sketch.get_minimum() << "\nMax = " << sketch.get_maximum() << "\nMedian = " << sketch.get_median() << endl;
		}
		
}