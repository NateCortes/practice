#ifndef ELEMENT_H
#define ELEMENT_H
//#include <stdio.h>

struct element{
  int data;

  struct element* next;
  struct element* prev;

  // element(){ printf("elem created");};
  //~element(){ printf( "elem destroyed");};

};

#endif
