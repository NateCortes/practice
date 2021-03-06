#include<iostream>
#include<climits>
#include <math.h>
using namespace std;

void swap( int *a, int *b);

class max_heap{
  int *Array
  int capacity
  int heap_size

  public:
      max_heap(int a[], int size);
      int parent(int i) {return (i-1) / 2;}
      int left(int i) {return (2 * i);}
      int right(int i) {return (2 * i) + 1;}

      void max_heapify(int i);
      int get_max() {return Array[0];}
      int extract_max();
};

max_heap::max_heap(int a[], int size){
  array = a;
  heap_size = size;
  int i = floor(heap_size / 2);
  while(i > 0){
    max_heapify(i);
    i--;
  }
}

max_heap::max_heapify(int i){
  int l = left(i);
  int r = right(i);
  int largest = i;

  if(l <= heap_size && Array[l] > A[i]){
    largest = l;
  }
  else{ largets = i;}

  if(r <= heap_size && Array[r] > A[i]){
    largest = r;
  }

  if( largest != i){
    swap(&Array[largest], &Array[i]);
    max_heapify(Array[largest]);
  }
}

max_heap::extract_max(){
  if(heap_size < 1) {
    cout << "no heap to extract from" << endl;
  }

  int max = get_max();
  Array[0] = Array[heap_size];
  heap_size = heap_size - 1;
  max_heapify(Array, 0);
  return max;
}
