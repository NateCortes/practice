#include "graph.h"

graph::graph( int e, int v){
	this->edges = e;
	this->vertecies = v;
	//allocates memeory needed for a double pointer
	this->adjacencies = (struct vertex**) malloc( v * sizeof(struct vertex));
	
	//assigns a vertext to each memory location
	vertex* point;
	for( int i=0;i < v; i++){
		point = new vertex( i);
		adjacencies[i] = point;
	}
}

graph::~graph(){
	//std::cout<<"graph destroyed"<<std::endl;
}

element* graph::find_connection( int u, int v){
	//finds adjacency list associated with vertex u 
	element* point = adjacencies[u];

	//moves through adjacency list to find the connected vertex
	while( point->next != NULL && point->vert != v){
		point = point->next;
	}	
	
	return point;
}

int graph::check_weight( int u, int v){
	//returns the edge weight connecting vertex u to v
	element* point = find_connection( u, v);
	return point->weight;
}

void graph::add_edge( int u, int v, int w){
	//adds a vertex and it's weight into the adjacency list at the head
	//connecting from u to v, with weight w
	
	element* node = new element( v, w);
	if(adjacencies[u] != NULL){	
		//inserts node at the head of the list
		node->next = adjacencies[u]->next;
		adjacencies[u]->next = node;
	}
}