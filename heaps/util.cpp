#include "util.h"

heap initialize( int n){
	//return heap object by NRVO
	heap pass = heap( n);
	return pass;
}

void build_heap( heap* pass, element* array){
	std::cout<<"building heap"<<std::endl;

	//array[4095] holds total count
	pass->heap_size = array[4095].key;

	//copy array into heap object
	for(int i = 0;i<pass->heap_size;i++){
		pass->sack[i] = array[i];
	}

	//build heap algorithm
	for(int jay=(pass->heap_size)/2;jay>=0;jay--){
		pass->heapify( jay);
	}

	std::cout<<"heap built"<<std::endl;
}

void insert( heap* pass, int k){
	element ins ( k);
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
		while(tester > -1){
			if(pass->sack[placer].key < pass->sack[tester].key){
				pass->swap(&pass->sack[placer], &pass->sack[tester]);
				placer = tester;
				tester = (placer - 1) / 2;
			}
			else{
				tester = -1;
			}
		}
	}
}

int delete_min( heap* pass){
	int min = pass->min();

	//switches first element location with last element location at heap_size,
	//decreases heap_size
	//then moves that element again to the capacity
	pass->swap( &pass->sack[0], &pass->sack[pass->heap_size - 1]);
	pass->swap( &pass->sack[pass->heap_size - 1], &pass->sack[pass->capacity - 1]);
	std::cout<<"new min: "<<pass->min()<<std::endl;

	pass->heap_size = pass->heap_size - 1;
	pass->heapify(0);

	return min;
}

void decrease_key( heap* pass, int idx, int key){
	if(pass->sack[idx].key > key){
		pass->sack[idx].key = key;

		//finds the right position to maintain heap property
		int placer = idx;
		int tester = (idx - 1) / 2;
		// while(tester > -1){
		// 	if(pass->sack[placer].key < pass->sack[tester].key){
		// 		pass->swap(&pass->sack[placer], &pass->sack[tester]);
		// 		placer = tester;
		// 		tester = (placer - 1) / 2;
		// 	}
		// 	else{
		// 		tester = -1;
		// 	}
		// }
		while(pass->sack[placer].key < pass->sack[tester].key && (placer > 0)){
				pass->swap(&pass->sack[placer], &pass->sack[tester]);
				placer = tester;
				tester = (placer - 1) / 2;
		}
	}
	else{
		std::cout<<"value lower than input change"<<std::endl;
	}
}

void print_heap( heap* pass){
	std::cout<<"--Printing Heap--"<<std::endl;
	pass->print();
	std::cout<<"-----------------"<<std::endl;
}
