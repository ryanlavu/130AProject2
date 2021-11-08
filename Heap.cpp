#include "Heap.h"

#include <iostream>

/* Constructor
 * bool isMax: true = max heap, false = min heap
 */
Heap::Heap(bool isMax) {

	max = isMax;
	size = 0;
	heap = new vector<int>();

}

/* Insert function
 * int element: element you want to insert into heap
 */
void Heap::insert(int element) {

	heap.push_back(element);
	orderLast();

}

/* Remove function
 * int target: element you want to remove from heap
 */
void Heap::remove(int target) {

	int targetIndex = -1;
	for(int i = 0; i < heap.size(); i++) {
	
		if(heap[i] == target) targetIndex = i;

	}

	if(targetIndex == -1) return;

	int temp = heap[targetIndex];
	heap[targetIndex] = heap.back();
	heap.pop_back();

	for(int i = targetIndex; i > 0; i = ((i - 1) / 2)) {

		if(max && (heap[i] > heap[(i - 1) / 2])) {

			temp = heap[i];
			heap[i] = heap[(i - 1) / 2];
			heap[(i - 1) / 2] = temp;

		} else if (!max && (heap[i] < heap[(i - 1) / 2])) {
	
			temp = heap[i];
			heap[i] = heap[(i - 1) / 2];
			heap[(i - 1) / 2] = temp;

		}
		
	}

}

/* Get root function
 * return: int value in the root
 */
int Heap:getRoot() {

}

/* Extract root function
 * return: int value in the root
 */
int Heap::extractRoot() {

	int value = getRoot();
	remove(getRoot());
	return value;

}

/* Get minimum function
 * return: int value of smallest value
 */
int Heap::getMin() {

	if(!max) return getRoot();

}

/* Get maximum function
 * return: int value of largest value
 */
int Heap::getMax() 

	if(max) return getRoot();

}

/* Get size function
 * return: int value of heap size
 */
int Heap::getSize() { return size; }

/* Search function
 * int target: value of element you want to find
 * return: boolean if element is found
 */
bool Heap::search(int target) {

}

/* Swap last function
 * int target: element that you want to swap with the last element
 */
void Heap::swapLast(int target) {

	int targetIndex = findIndex(target);
	if(targetIndex == -1) return;
	
	int temp = heap[targetIndex];
	heap[targetIndex] = heap[heap.size() - 1];
	heap[heap.size() - 1] = temp;

}

/* Find index function
 * int target: element that you want to find index of
 * return: index of the target element and -1 if not found
 */
int Heap::findIndex(int target) {

	for(int i = 0; i < heap.size(); i++) {

		if(heap[i] == target) return i;

	}

	return -1;

}

/* Order last function
 * Bubbles up the last element in vector to sort
 */
void Heap::orderLast() {

	for(int i = heap.size(); i > 0; i = ((i - 1) / 2)) {

		if(max && (heap[i] > heap[(i - 1) / 2])) {
			
			int temp = heap[i];
			heap[i] = heap[(i - 1) / 2];
			heap[(i - 1) / 2] = temp;

		} else if (!max && (heap[i] < heap[(i - 1) / 2])) {

			int temp = heap[i];
			heap[i] = heap[(i - 1) / 2];
			heap[(i - 1) / 2] = temp;

		}

	}

}
