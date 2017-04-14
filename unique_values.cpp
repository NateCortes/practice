#include <stdlib.h>
#include <iostream>

void insertion_sort( int*, int);
int unique( int*, int*, int);

int main( void){

  int test_array[10] =  { 1, 2, 2, 2, 4, 3, 5, 5 ,3 ,3};
  int point[10];  
  int point_size;
  

  std::cout<<"----find unique values----"<<std::endl;
  //for(int i=0;i<10;i++){
  //  std::cout<<test_array[i]<<" ";
  // }
  //std::cout<<std::endl;
 
  insertion_sort( test_array, 10);

  for(int i=0;i<10;i++){
    std::cout<<test_array[i]<<" ";
  }
  std::cout<<std::endl;
  
  point_size =  unique( test_array, point, 10);

  std::cout<<"----unique values----"<<std::endl;
  for(int i=0;i<point_size;i++){
    std::cout<<point[i]<<" "; 
  }
  std::cout<<std::endl;
	
  return 0;
}

void insertion_sort( int* ary, int end){
  for( int i=1;i<end;i++){
      int key = ary[i];
      int jay = i-1;
      while(jay >= 0 && ary[jay] > key){
	ary[jay + 1] = ary[jay];
	jay -= 1;
      }
      ary[jay + 1] = key;
  }
}

int unique( int* ary, int* unique, int size){
  int count = 0;
 
  for(int i=0;i<size-1;i++){
    if((ary[i] != ary[i+1])){
      unique[count] = ary[i];
      count+=1;
    }
  }
  unique[count] = ary[size-1];
  return count+1;
}
