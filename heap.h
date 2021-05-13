#ifndef HEAP_H_
#define HEAP_H_

struct ELEMENT // struct for elements in heap
{
	int key;
};

class Heap
{
private:
	int capacity;
	int size;
	struct ELEMENT* H;

public:
	Heap(int cap);
	Heap(int cap, int s, int a[]);
	int getSize();
	int getCapacity();
	int getElement(int index);
	void setSize(int s);
	void setCapacity(int c);
	void setElement(int index, int value);
};
#endif // !HEAP_H_