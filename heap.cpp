#include "heap.h"


Heap::Heap(int cap)
{
	capacity = cap;
	size = 0;
	H = new ELEMENT[cap];
}

Heap::Heap(int cap, int s, int a[])
{
	capacity = cap;
	size = s;
	H = new ELEMENT[cap];
}

int Heap::getSize()
{
	return size;
}

int Heap::getCapacity()
{
	return capacity;
}

int Heap::getElement(int index)
{
	return H[index].key;
}

void Heap::setSize(int s)
{
	size = s;
}

void Heap::setCapacity(int c)
{
	capacity = c;
}

void Heap::setElement(int index, int value)
{
	H[index].key = value;
}
