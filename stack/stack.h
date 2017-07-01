#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <iostream>
#include "element.h"

struct stack{
 
  element* head;
  int size;

  stack();
 

  void push( element*);
  void pop();
  void print();
  int size_of();
  
};

#endif
