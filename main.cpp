#include <stdio.h> 
#include <stdlib.h>
#include "util.h"
#include "heap.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	char c;
	int i, v, f;
	Heap* heap = NULL;

	while (1)
	{
		c = nextCommand(&i, &v, &f);
		
		switch (c)
		{
			case 'S':
			{
				printf("COMMAND: %c. \n", c);
				exit(0);
			}
			case 'C':
			{
				printf("COMMAND: %c %d. \n", c, v);
				free(heap);
				heap = Initialize(v);
				break;
			}
			case 'R': // needs work
			{
				printf("COMMAND: %c. \n", c);
				if (heap == NULL) 
				{
					printf("Sorry!!! It cannot be done. Please initialize the heap first.\n");
				}
				else
				{
					free(heap);
					heap = load("HEAPinput.txt");
				}
				break;
			}
			case 'W':
			{
				printf("COMMAND: %c. \n", c);
				if (heap == NULL)
				{
					printf("Sorry!!! It cannot be done. Please initialize the heap first.\n");
				}
				else
				{
					printHeap(heap);
				}
				break;
			}
			case 'I':
			{
				printf("COMMAND: %c %d %d. \n", c, f, v);
				if (heap == NULL)
				{
					printf("Sorry!!! It cannot be done. Please initialize the heap first.\n");
				}
				else
				{
					Insert(heap, f, v);
				}
				break;
			}
			case 'D':
			{
				printf("COMMAND: %c %d. \n", c, f);
				if (heap == NULL)
				{
					printf("Sorry!!! It cannot be done. Please initialize the heap first and put the elements into it.\n");
				}
				else
				{
					DeleteMin(heap, f);
				}
				break;
			}
			case 'K':
			{
				printf("COMMAND: %c %d %d %d. \n", c, f, i, v);
				if (heap == NULL)
				{
					printf("Sorry!!! It cannot be done. Please initialize the heap first and put the elements into it.\n");
				}
				else
				{
					DecreaseKey(heap, f, i, v);
				}
				break;
			}
			default:
			{
				break;
			}
		}
	}

}