#include <stdlib.h>
#include <iostream>
#include "element.h"

#ifndef HEAP_H
#define HEAP_H

class heap{
public:
	int capacity, heap_size;
	vertex** sack;
	
	heap( int size);
	~heap();
		
	vertex* min() { return sack[0];}
	void heapify(int index);
	int find_element( int vertex);
	void swap(vertex* a, vertex* b);
};
#endif
