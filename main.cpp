#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "MinMedianMaxSketch.cpp"

using namespace std;

int main(int argc, char *argv[]) {
		string heapOrSketch = argv[1];
		string query;
		int queryToInt;

		if(heapOrSketch == "heap")
		{
			Heap<int> maxHeap(true);
			Heap<int> minHeap(false);
			
			//insert into heaps
			ifstream insertFile(argv[2]);
			while(getline(insertFile, query))
			{
				if(query.empty())
					break;
				queryToInt = stoi(query);
				maxHeap.insert(queryToInt);
				minHeap.insert(queryToInt);
			}	
			//cout << "after inserting int heap\nmaxHeap:" << endl;
			//maxHeap.printOut();
			//cout << "after inserting int eahp\nminJeap:" << endl;
			//minHeap.printOut();
			insertFile.close();


			//delete from heaps
			ifstream deleteFile(argv[3]);
			while(getline(deleteFile, query))
			{
				if(query.empty())
					break;
				queryToInt = stoi(query);
				if(maxHeap.getRoot() == queryToInt)
				{
					maxHeap.extractRoot();
				}
				else
				{
					maxHeap.remove(queryToInt);
				}
				if(minHeap.getRoot() == queryToInt)
				{
					minHeap.extractRoot();
				}
				else
				{
					minHeap.remove(queryToInt);
				}
			}	
			deleteFile.close();

			//report stats
			//cout << "after removing elements heap\nminHeap:" << endl;
			//minHeap.printOut();
			//cout << "after removing elements heap\nmaxHeap:" << endl;
			//maxHeap.printOut();
			cout << "Min Heap:\n" << "Size = " << minHeap.getSize() << "\nMin = " << minHeap.getMin() << "\nMax = " << minHeap.getMax() << endl;
			cout << "Max Heap:\n" << "Size = " << maxHeap.getSize() << "\nMin = " << maxHeap.getMin() << "\nMax = " << maxHeap.getMax() << endl;
			//cout << "is 99957 in maxHeap? " << maxHeap.search(99957) << endl;
			maxHeap.printOut();
		}
		else
		{
			MinMedianMaxSketch<int> * sketch = new MinMedianMaxSketch<int>();

			//insert into sketch
			ifstream insertFile(argv[2]);
			while(getline(insertFile, query))
			{
				if(query.empty())
					break;
				queryToInt = stoi(query);
				sketch->insert(queryToInt);
			}	
			insertFile.close();

			//delete from sketch
			ifstream deleteFile(argv[3]);
			while(getline(deleteFile, query))
			{
				if(query.empty())
					break;
				queryToInt = stoi(query);
				sketch->remove(queryToInt);
			}	
			deleteFile.close();

			//report stats
			cout << "MinMedianMaxSketch:\n" << "Size = " << sketch->get_size() << "\nMin = " << sketch->get_minimum() << "\nMax = " << sketch->get_maximum() << "\nMedian = " << sketch->get_median() << endl;
		}
		
}
