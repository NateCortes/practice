#ifndef ELEMENT_H
#define ELEMENT_H	

struct element{
	int vert; 	//vertex pointed to 
	int weight;	//weight of edge
	
	element* next;

	element( int v, int w){
		vert = v;
		weight = w;
		next = NULL;	
	};	
	element(){};	
	~element(){};
};

struct vertex : element{
	int name;	//vertex number
	int distance;	//distance from shortest path node start
	
	vertex* parent;	//parent for shortest path algorithm

	vertex( int val){
		distance = 999;		
		name = val;
		parent = NULL;
	};

	vertex( const vertex& cpy){
		name = cpy.name;
		distance = cpy.distance;
		
	};
	
	vertex(){};
	~vertex(){};
};
#endif
