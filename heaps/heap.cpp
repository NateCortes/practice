#include "heap.h"

heap::heap( int size){
	capacity = size;
	heap_size = 0;
	sack = new element[size];
	std::cout<<"heap created"<<std::endl;
}

heap::heap( const heap& other, int size){
	//other( size);
	std::cout<<"copy created"<<std::endl;
}

heap::~heap(){
	//delete[] sack;
	std::cout<<"heap destroyed"<<std::endl;	
}

void heap::print(){
	for(int i=0;i<heap_size;i++){
		std::cout<<sack[i].key<<" ";
	}
	std::cout<<std::endl;
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

	if(l < this->heap_size && sack[l].key < sack[index].key){
		smallest = l;
	}
	else{
		smallest = index;
	}

	if(r < this->heap_size && sack[r].key < sack[index].key && sack[r].key < sack[l].key){
		smallest = r;
	}
	
	if(smallest != index){
		this->swap(&sack[smallest], &sack[index]);
		heapify(smallest);
	}
}

void heap::swap( element* a, element* b){
	int temp = a->key;
	a->key = b->key;
	b->key = temp;
}
