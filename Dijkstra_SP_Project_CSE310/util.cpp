#include "util.h"

/////Init methods///////////////////////

heap initialize( int n){
	//return heap object by NRVO
	heap pass = heap( n);
	return pass;
}

graph* init_graph( int v, int e){
	//allocates memory for a graph object and returns its pointer
	graph* pass = new graph( v, e);
	return pass;
}
/////End of init methods////////////////

/////Heap Methods///////////////////////

void build_heap( heap* pass, graph* graph_pass){
	
	//change the heap_size
	pass->heap_size = graph_pass->vertecies;
	
	//deep copy array into heap object
	//only copies namd and distance values to be used in Dijktsra's SP algorithm		
	for(int i = 0;i<pass->heap_size;i++){
		pass->sack[i] = (struct vertex*) malloc( sizeof( struct vertex));	
		pass->sack[i]->distance = graph_pass->adjacencies[i]->distance;
		pass->sack[i]->name = graph_pass->adjacencies[i]->name;	
	}

	//build heap algorithm
	for(int jay=(pass->heap_size)/2;jay>=0;jay--){
		pass->heapify( jay);
	}
}

void insert( heap* pass, vertex* ins){
	if(pass->heap_size == pass->capacity){
		std::cout<<"heap is full"<<std::endl;
	}
	else{
		//adds element to the end of heap_size
		pass->heap_size = pass->heap_size + 1;
		pass->sack[pass->heap_size-1] = ins;
		
		//finds right position to maintain heap property
		int placer = pass->heap_size-1;
		int tester = (placer - 1) / 2;
		while((tester > -1) && (pass->sack[placer]->distance < pass->sack[tester]->distance)){
				pass->swap( pass->sack[placer], pass->sack[tester]);
				placer = tester;
				tester = (placer - 1) / 2;			
		}
	}	
}

vertex* delete_min( heap* pass){
	vertex* min = (struct vertex*) malloc( sizeof(struct vertex));
	min->distance = pass->min()->distance;
	min->name = pass->min()->name;
	
	//switches first element location with last element location at heap_size, 
	//decreases heap_size,
	//then moves that element again to the location at capacity
	pass->swap( pass->sack[0], pass->sack[pass->heap_size - 1]);
	pass->swap( pass->sack[pass->heap_size - 1], pass->sack[pass->capacity - 1]);

	pass->heap_size = pass->heap_size - 1;
	pass->heapify(0);
	
	return min;
}

void decrease_key( heap* pass, int idx, int key){
	if( idx == -1 || idx > pass->heap_size){ 
		std::cout<<"index out of heap bounds, "<<idx<<std::endl;		
		return;
	}
	if(pass->sack[idx]->distance > key){
		pass->sack[idx]->distance = key;
		
		//finds the right position to maintain heap property
		int placer = idx;
		int tester = (idx - 1) / 2;
		while((tester > -1) && (pass->sack[placer]->distance < pass->sack[tester]->distance)){
				pass->swap( pass->sack[placer], pass->sack[tester]);
				placer = tester;
				tester = (placer - 1) / 2;			
		}		
	}
	else{
		std::cout<<"value lower than input change"<<std::endl;
	}
}
/////End of heap methods////////////////

/////Dijktsra SP methods////////////////

void Dijktsra_SP( graph* pass, int start, int end){
	init( pass, --start);
	heap* queue = new heap( pass->vertecies);
	build_heap( queue, pass);
	
	while( queue->heap_size > 0){

		vertex* temp = delete_min( queue);
	
		element* list = pass->adjacencies[temp->name]->next;

		while( list != NULL){
			int wait = pass->check_weight( temp->name, list->vert);
			if( temp->distance == INT_MAX){

				temp->distance = wait;
				pass->adjacencies[ temp->name]->distance = wait;
				
				insert( queue, temp);	
			}
			else{	
				relax( temp, pass->adjacencies[(list->vert) - 1], wait,  queue);
			}	
			list = list->next; 
		}
	}

}

void init( graph* pass, int start){
	//initializes graph for a BFS
	//sets all distance values to INT_MAX and all parents to NULL
	for(int i =0; i<pass->vertecies; i++){ 
		vertex* point = pass->adjacencies[i];
		point->distance = INT_MAX;
		point->parent = NULL;
	}
	
	//sets start node distance to 0
	pass->adjacencies[start]->distance = 0;
}

void relax( vertex* you, vertex* vee, int weight , heap* pass){

	if( vee->distance > you->distance + weight){	
		vee->distance = you->distance + weight;
		vee->parent = you;	

		//find the veretx node with vee->name == name
		//int temp = pass->find_element( vee->name);
		decrease_key( pass, pass->find_element(vee->name), (you->distance + weight));
	}
}
/////End of Dijktsra SP methods///////////////////

/////print methods////////////////////////////////

void print_heap( heap* pass){
	//prints the heap to stdout
	std::cout<<"--Printing Heap--"<<std::endl;

	if(pass->sack != NULL){
	std::cout<<"heap size: "<<pass->heap_size<<std::endl;
	for(int i=0;i<pass->heap_size;i++){
		if(pass->sack[i] != NULL){
			std::cout<<i<<": "<<pass->sack[i]->distance<<"("<<pass->sack[i]->name<<")"<<std::endl;
		}
	}
	}
	std::cout<<"\n-----------------"<<std::endl;
}

void print_graph( graph* pass){
	//prints the graph to stdout
	std::cout<<"--Printing Graph--"<<std::endl;
	std::cout<< pass->vertecies<<" verticies"<<" | "<< pass->edges<<" edges"<<std::endl;	

	element* point = NULL;
	for(int i=0;i<pass->vertecies;i++){
		point = pass->adjacencies[i]->next;
		std::cout<<(i + 1)<<" : ";//<<" [P: "<<find_parent_name(pass->adjacencies[i])<<" d: "<<pass->adjacencies[i]->distance<<"] : ";	
		while( point != NULL){
			std::cout<<"("<<point->vert<<","<<point->weight<<")";
			point = point->next;	
		}
		std::cout<<std::endl;
	}
	std::cout<<"------------------"<<std::endl;
}

void print_vertex( vertex* pass){
	std::cout<<"v("<<pass->name + 1<<" "<<pass->distance<<") ";
}

void print_parent_path( vertex* pass, graph* graph_pass){
	
	//base case start node has no parent
	if(pass->parent == NULL){
		std::cout<<(pass->name) + 1<<" ";
		return;
	}	
	
	//recursive call grabs parent from graph adjcency list
	print_parent_path( graph_pass->adjacencies[ find_parent_name( pass) - 1], graph_pass);
	
	//prints parent name
	std::cout<<(pass->name) + 1<<" ";
	return;
}

int find_parent_name( vertex* pass){
	//utility method to avoid segmention fault if no parent exists
	int val = 0;
	if( pass->parent != NULL){
		val = pass->parent->name + 1;
	}	
	return val;
}
/////end print methods/////////////////////////////