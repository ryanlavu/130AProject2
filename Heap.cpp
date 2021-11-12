#include <vector>
#include <iostream>

#include <string>

using namespace std;

template<class T>
class Heap {

	public:

	/* Constructor
	* bool isMax: true = max heap, false = min heap
	*/
	Heap(bool isMax) {
		
		max = isMax;
		size = 0;
		
	}

	/* Insert function
	* int element: element you want to insert into heap
	*/
	void insert(T element) {
		
		// Insert element into the last slot of tree
		heap.push_back(element);

		// Function that bubbles up the last element
		orderLast();
		setSize(getSize() + 1);
		
	}

	/* Remove function
	* int target: element you want to remove from heap
	*/
	void remove(T target) {

		int targetIndex = -1;

		// Find index of the target we want to remove
		for(int i = 0; i < heap.size(); i++) {

			if(heap[i] == target) targetIndex = i;

		}

		// If target isn't found exit
		if(targetIndex == -1) return;

		// Replace the value at targetIndex with the last value
		T temp = heap[targetIndex];
		heap[targetIndex] = heap.back();

		// Remove the last element which should be the target
		heap.pop_back();
		size--;

		bool shifted = false;

		// Bubble up from the targetIndex
		for(int i = targetIndex; i > 0; i = ((i - 1) / 2)) {

			if(max && (heap[i] > heap[(i - 1) / 2])) {

				temp = heap[i];
				heap[i] = heap[(i - 1) / 2];
				heap[(i - 1) / 2] = temp;
				shifted = true;

			} else if(!max && (heap[i] < heap[(i - 1) / 2])) {

				temp = heap[i];
				heap[i] = heap[(i - 1) / 2];
				heap[(i - 1) / 2] = temp;
				shifted = true;

			} else if((max && (heap[i] < heap[(i - 1) / 2])) || (!max && (heap[i] > heap[(i - 1) / 2]))) {

				break;

			}

		}

		// Check if the element moved up if so return
		if(shifted) return;


		// Move the element down if necessary by comparing to two children
		while(targetIndex < heap.size()) {

			int leftChild = (2 * targetIndex) + 1;
			int rightChild = (2 * targetIndex) + 2;

			bool left = true;
			bool right = true;

			if(heap.size() <= leftChild) left = false;
			if(heap.size() <= rightChild) right = false;

			if(max && (heap[targetIndex] < heap[leftChild]) && left) {

				T temp = heap[targetIndex];
				heap[targetIndex] = heap[leftChild];
				heap[leftChild] = temp;
				targetIndex = leftChild;

			} else if(max && (heap[targetIndex] < heap[rightChild]) && right) {

				T temp = heap[targetIndex];
				heap[targetIndex] = heap[rightChild];
				heap[rightChild] = temp;
				targetIndex = rightChild;

			} else if(!max && (heap[targetIndex] > heap[leftChild]) && left) {

				T temp = heap[targetIndex];
				heap[targetIndex] = heap[leftChild];
				heap[leftChild] = temp;
				targetIndex = leftChild;

			} else if(!max && (heap[targetIndex] > heap[rightChild]) && right) {

				T temp = heap[targetIndex];
				heap[targetIndex] = heap[rightChild];
				heap[rightChild] = temp;
				targetIndex = rightChild;

			} else {

				return;

			}

		}

	}

	/* Get root function
	* return: int value in the root
	*/
	T getRoot() {
		
		// Root should be at 0 index of the vector
		return heap[0];
		
	}

	/* Extract root function
	* return: int value in the root
	*/
	T extractRoot() {

		// Save value of root in order to not lose when removing
		T value = getRoot();

		// Call removed function targeting the value of the root
		remove(value);

		// Return the saved value
		return value;

	}

	/* Get minimum function
	* return: int value of smallest value
	*/
	T getMin() {

		// If min heap then simply return the root
		if(!max) return getRoot();

		T min = heap[0];

		// If max heap then iterate through the entire vector
		for(int i = 1; i < heap.size(); i++) {

			if(heap[i] < min) min = heap[i];

		}

		return min;

	}

	/* Get maximum function
	* return: int value of largest value
	*/

	T getMax() {

		// If max heap then simply return the root
		if(max) return getRoot();

		T maxValue = heap[0];

		// If min heap then iterate through the entire vector
		for(int i = 1; i < heap.size(); i++) {

			if(heap[i] > maxValue) maxValue = heap[i];

		}

		return maxValue;

	}


	int getSize() { return size; }


	/* Search function
	* int target: value of element you want to find
	* return: boolean if element is found
	*/
	bool search(T target) {

		// Iterate through the entire vector in order to find target element
		for(int i = 0; i < heap.size(); i++) {

			if(heap[i] == target) return true;

		}

		return false;
	}

	/* Order last function
	 * Bubbles up the last element in vector to sort
	 */
	void orderLast() {

		// Starting at the last element compare with it's parent nodes
		for(int i = heap.size(); i > 0; i = ((i - 1) / 2)) {

			if(max && (heap[i] > heap[(i - 1) / 2])) {

				T temp = heap[i];
				heap[i] = heap[(i - 1) / 2];
				heap[(i - 1) / 2] = temp;

			} else if (!max && (heap[i] < heap[(i - 1) / 2])) {

				T temp = heap[i];
				heap[i] = heap[(i - 1) / 2];
				heap[(i - 1) / 2] = temp;

			}

		}

	}

	void setSize(int setTo){ size = setTo; }
		
	private:
		bool max;
		vector<T> heap;
		int size;
	
};




