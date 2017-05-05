#include <stdlib.h>
#include <iostream>
#include "element.h"

#ifndef HEAP_H
#define HEAP_H

class heap{
public:
	int capacity, heap_size;
	element *sack;
	
	heap( int size);
	heap( const heap&, int size);
	~heap();
		
	int min() { return sack[0].key;}
	void print();
	void heapify(int index);
	void swap(element* a, element* b);
};
#endif
