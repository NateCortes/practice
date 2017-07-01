#ifndef ELEMENT_H
#define ELEMENT_H
#include <stdlib.h>
#include <iostream>

struct element{
  int data;

  element* next;
  element* prev;

  element(){ std::cout<<"elem created"<<std::endl;};
  ~element(){ std::cout<<"elem destroyed"<<std::endl;};

};

#endif
