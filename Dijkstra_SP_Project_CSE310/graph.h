#include <stdlib.h>
#include <iostream>
#include "element.h"
using namespace std;

#ifndef GRAPH_H
#define GRAPH_H
class graph{
public:
	int edges;	//number of edges	
	int vertecies;	//number of verticies
	
	vertex** adjacencies;	//linked list holding edges

	graph( int, int);
	~graph();
	int check_weight( int, int);
	void add_edge( int, int, int);
	element* find_connection( int u, int v);

};
#endif //GRAPH_H