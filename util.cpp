#include "util.h"
#include <fstream>
#include <string>
#include <cstring>
#include "heap.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace std;

Heap* load(string file)
{
	int count = 0;
	ifstream stm;
	Heap* heap = NULL;

	stm.open(file); // opens the file

	if (stm.is_open())
	{
		stm >> count;
		int arr[count];

		for (int i = 0; i < count; i++)
		{
			stm >> arr[i];
		}
		free(heap);
		heap = new Heap(count, count, arr);

	}
	else
	{
		printf("There was a problem opening file HEAPinput.txt for reading.");
	}
	stm.close();

	return heap;
}

char nextCommand(int *index, int *val, int *flag)
{
	char c;

	while (1)
	{
		scanf("%c", &c);

		if (c == 'S' || c == 's') // program stops
		{
			c = 'S';
			break;
		}
		if (c == 'C' || c == 'c') // creates empty heap
		{
			c = 'C';
			scanf("%d", val);
			break;
		}
		if (c == 'R' || c == 'r') // loads file and builds
		{
			c = 'R';
			break;
		}
		if (c == 'W' || c == 'w') // prints heap
		{
			c = 'W';
			break;
		}
		if (c == 'I' || c == 'i') // inserts element
		{
			c = 'I';
			scanf("%d", flag);
			scanf("%d", val);
			break;
		}
		if (c == 'D' || c == 'd') // deletes min
		{
			c = 'D';
			scanf("%d", flag);
			break;
		}
		if (c == 'K' || c == 'k') // decreases key
		{
			c = 'K';
			scanf("%d", flag);
			scanf("%d", index);
			scanf("%d", val);
			break;
		}
		
	}

	return c;
}

Heap* Initialize(int n)
{
	Heap* list = new Heap(n);

	return list;
}

void BuildHeap(Heap* heap, ELEMENT A[], int n)
{
	heap->setSize(n);

	for (int i = 1; i <= heap->getSize(); i++) // copies elements in array A to the heap
	{
		heap->setElement(i, A[i].key);
	}

	for (int i = heap->getSize() / 2; i > 0; i--)
	{
		MIN_HEAPIFY(heap, i);
	}
}

void Insert(Heap* heap, int flag, int k)
{
	if (flag == 2)
	{
		printHeap(heap);
	}

	heap->setSize(heap->getSize() + 1); // increas size by 1
	heap->setElement(heap->getSize(), k);

	DecreaseKey(heap, 1, heap->getSize(), heap->getElement(heap->getSize()));

	if (flag == 2)
	{
		printHeap(heap);
	}
}

int DeleteMin(Heap* heap, int flag)
{
	int max;

	if (heap->getSize() < 1)
	{
		return 0; // edit later
	}
	else
	{
		max = heap->getElement(1);
		heap->setElement(1, heap->getElement(heap->getSize()));
		heap->setSize(heap->getSize() - 1);
		MIN_HEAPIFY(heap, 1);
		return max;
	}
}

void DecreaseKey(Heap* heap, int flag, int index, int value)
{
	if (flag == 2)
	{
		printHeap(heap);
	}

	if (value > heap->getElement(index))
	{
		return;
	}
	else
	{
		heap->setElement(index, value);

		while (index > 1 && heap->getElement(index / 2) > heap->getElement(index))
		{
			int temp = heap->getElement(index);
			heap->setElement(index, heap->getElement(index / 2));
			heap->setElement(index / 2, temp);
		}
	}

	if (flag == 2)
	{
		printHeap(heap);
	}
}

void printHeap(Heap* heap)
{
	cout << "The capacity is ";
	cout << heap->getCapacity() + "." << endl;
	cout << "Size is ";
	cout << heap->getSize() + "." << endl;

	if (heap != NULL)
	{
		for (int i = 1; i <= heap->getSize(); i++)
		{
			cout << heap->getElement(i) << endl;
		}
	}
}

void MIN_HEAPIFY(Heap* heap, int i)
{
	int smallest = i;
	int l = i * 2;
	int r = (i * 2) + 1;

	if (l <= heap->getSize() && heap->getElement(l) < heap->getElement(i))
	{
		smallest = l;
	}

	if (r <= heap->getSize() && heap->getElement(r) < heap->getElement(i))
	{
		smallest = r;
	}

	if (smallest != i)
	{
		int temp = heap->getElement(i);
		heap->setElement(i, heap->getElement(smallest));
		heap->setElement(smallest, temp);

		MIN_HEAPIFY(heap, smallest);
	}
}
