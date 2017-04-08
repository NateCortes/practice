#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <stdlib.h>
#include "element.h"
#include "heap.h"

class heap;

	heap initialize(int);
	int delete_min(heap*);
	void print_heap(heap*);
	void build_heap(heap*, element*);
	void decrease_key(heap*, int, int);
	void insert(heap*, int);
#endif
