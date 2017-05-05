#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <stdlib.h>
#include <climits>
#include "element.h"
#include "heap.h"
#include "graph.h"

class heap;
class graph;
	//init methods
	heap initialize(int);
	graph* init_graph( int, int);	

	//print methods
	void print_heap(heap*);
	void print_graph( graph*);
	void print_vertex( vertex*);
	void print_parent_path( vertex* , graph*);

	//heap methods
	vertex* delete_min(heap*);
	void insert(heap*, vertex);
	void build_heap(heap*, graph*);
	void decrease_key(heap*, int, int);
	
	//shortest path methods
	void init( graph*, int);
	int find_parent_name( vertex*);
	void Dijktsra_SP( graph*, int, int); 	
	void relax( vertex*, vertex*, int, heap*);
	
#endif
