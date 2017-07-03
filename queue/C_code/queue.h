#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include "element.h"

struct queue{
  struct element* head;
  struct element* tail;
  int size;
};

struct queue* init_queue();
struct element* dequeue( struct queue*);
void enqueue( struct queue* ,  struct element* );
void print_q( struct queue*);

#endif
