#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <iostream>
#include "element.h"

class OSqueue{
 public: 
  element* head;
  element* tail;
  int size;

  OSqueue();
 
  void enqueue( element*);
  void dequeue();
  void print();
  int size_of();
  
};

#endif
