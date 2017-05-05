#include "heap.h"

heap::heap( int size){
	capacity = size;
	heap_size = 0;
	sack = (struct vertex**) malloc(size * sizeof( struct vertex));
	//std::cout<<"heap created"<<std::endl;
}

heap::~heap(){
	//delete[] sack;
	std::cout<<"heap destroyed"<<std::endl;	
}

void heap::heapify( int index){
		
	//maintins heap property by checking left and right children
	int l = 2*index;
	int r = (2*index) + 1;
	int smallest;

	if(index == 0){
		l = 1;
		r = 2;
	}
	
	if(l < this->heap_size && sack[l]->distance < sack[index]->distance){
		smallest = l;
	}
	else{
		smallest = index;
	}

	if(r < this->heap_size && sack[r]->distance < sack[index]->distance && sack[r]->distance < sack[l]->distance){
		smallest = r;
	}
	
	if(smallest != index){
		this->swap( sack[smallest],  sack[index]);
		heapify( smallest);
	}
}

int heap::find_element( int index){
	//locates the veretx with vertex->name == index
	//if it exists

	int i = 0;
	while( (i<heap_size) && (sack[i]->name != index)){
		i = i + 1;
	}	
	
	if( i == heap_size){
	//returns -1 if there is no vertex in heap with name == index
		return -1;
	}
	return i;
}

void heap::swap( vertex* a, vertex* b){
	vertex temp = *a;
	*a = *b;
	*b = temp;
}
