#include <fstream>
#include <string>
#include "heap.h"
using namespace std;

	Heap* load(string file);
	char nextCommand(int* i, int* v, int* f);
	Heap* Initialize(int n);
	void BuildHeap(Heap* heap, ELEMENT A[], int n);
	void Insert(Heap* heap, int flag, int k);
	int DeleteMin(Heap* heap, int flag);
	void DecreaseKey(Heap* heap, int flag, int index, int value);
	void printHeap(Heap* heap);
	void MIN_HEAPIFY(Heap* heap, int i);




