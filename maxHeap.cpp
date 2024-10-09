#include <iostream>
using namespace std;

class MaxHeap {
private:
	int* heap;
	int size;
	int capacity;
public:
	MaxHeap(int inputCapacity) {
		capacity = inputCapacity;
		size = 0;
		heap = new int[capacity];
	}

	MaxHeap(int* inputHeap, int inputSize, int inputCapacity) {
		capacity = inputCapacity;
		size = inputSize;
		heap = new int[capacity];
		for (int i = 0; i < inputSize; i++) {
			heap[i] = inputHeap[i];
		}
	}

	int getSize() {return size;}

	int getCapacity() {return capacity;}

	int parentIndex(int i) {
		return (i - 1) / 2;
	}

	int leftChildIndex(int i) {
		return 2 * i + 1;
	}

	int rightChildIndex(int i) {
		return 2 * i + 2;
	}

	int getMax() {
		if (size == 0) {
			cout << "Heap is empty; no maximum value.\n";
			return -1;
		}
		return heap[0];
	}

	int extractMax() {
		if (size == 0) {
			cout << "Heap is empty; unable to extract max\n";
			return -1;
		}

		int maxVal = heap[0];
		heap[0] = heap[size - 1];
		size--;

		int current = 0;
		while (true) {
			int left = leftChildIndex(current);
			int right = rightChildIndex(current);
			int largest = current;

			if (left < size && heap[left] > heap[largest]) {
				largest = left;
			}
			if (right < size && heap[right] > heap[largest]) {
				largest = right;
			}

			if (largest != current) {
				swap(heap[current], heap[largest]);
				current = largest;
			} else {
				break;
			}
		}

		return maxVal;
	}

	void insert(int val) {
		if (capacity == size) {
			cout << "Heap is full; unable to insert\n";
			return;
		}

		int current = size;
		heap[size] = val;
		size++;

		while (current > 0 && heap[parentIndex(current)] < heap[current]) {
			swap(heap[current], heap[parentIndex(current)]);
			current = parentIndex(current);
		}
	}


	void printHeap() {
		int level = 1;
		int levelCount = 1;
		for (int i=0; i < size; i++) {
			cout << heap[i] << " ";
			if (levelCount == level) {
				cout << endl;
				level *= 2;
				levelCount = 1;
			}
			else {
				levelCount++;
			}
		}
		cout << endl;
	}
};

int main() {
	int heapEntries[] = {7,6,5,4,3,2,1};
	MaxHeap testHeap(heapEntries, 7, 15);

	cout << "The heap entries are:\n";
	testHeap.printHeap();
	cout << endl;

	for (int i = 1; i <= 6; i++) {
		cout << "The parent of index " << i << " is at index " << testHeap.parentIndex(i) << endl;
	}
	for (int i = 0; i <= 2; i++) {
		cout << "The left child of index " << i << " is at index " << testHeap.leftChildIndex(i) << endl;
		cout << "The right child of index " << i << " is at index " << testHeap.rightChildIndex(i) << endl;
	}
	cout << endl;

	cout << "The maximum value in the heap is " << testHeap.getMax() << endl << endl;

	testHeap.insert(10);
	cout << "After inserting 10, the heap entries are:\n";
	testHeap.printHeap();

	testHeap.insert(15);
	cout << "After inserting 15, the heap entries are:\n";
	testHeap.printHeap();

	testHeap.insert(12);
	cout << "After inserting 12, the heap entries are:\n";
	testHeap.printHeap();

	testHeap.insert(9);
	cout << "After inserting 9, the heap entries are:\n";
	testHeap.printHeap();

	cout << "The maximum value is " << testHeap.extractMax() << endl;
	cout << "After removing the maximum, the heap values are:\n";
	testHeap.printHeap();

	testHeap.insert(14);
	cout << "After inserting 14, the heap entries are:\n";
	testHeap.printHeap();

	testHeap.insert(18);
	cout << "After inserting 18, the heap entries are:\n";
	testHeap.printHeap();

	cout << "The maximum value is " << testHeap.extractMax() << endl;
	cout << "After removing the maximum, the heap values are:\n";
	testHeap.printHeap();

	cout << "The maximum value is " << testHeap.extractMax() << endl;
	cout << "After removing the maximum, the heap values are:\n";
	testHeap.printHeap();

	cout << "The maximum value is " << testHeap.extractMax() << endl;
	cout << "After removing the maximum, the heap values are:\n";
	testHeap.printHeap();

	testHeap.insert(11);
	cout << "After inserting 11, the heap entries are:\n";
	testHeap.printHeap();

	cout << "The maximum value is " << testHeap.extractMax() << endl;
	cout << "After removing the maximum, the heap values are:\n";
	testHeap.printHeap();

	cout << "The maximum value is " << testHeap.extractMax() << endl;
	cout << "After removing the maximum, the heap values are:\n";
	testHeap.printHeap();

	testHeap.insert(20);
	cout << "After inserting 20, the heap entries are:\n";
	testHeap.printHeap();

	cout << "The maximum value is " << testHeap.extractMax() << endl;
	cout << "After removing the maximum, the heap values are:\n";
	testHeap.printHeap();

	cout << "The maximum value is " << testHeap.extractMax() << endl;
	cout << "After removing the maximum, the heap values are:\n";
	testHeap.printHeap();

	cout << "The maximum value is " << testHeap.extractMax() << endl;
	cout << "After removing the maximum, the heap values are:\n";
	testHeap.printHeap();
}