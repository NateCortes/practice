#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include "element.h"

struct queue{
  struct TCB_t* head;
  struct TCB_t* tail;
  int size;
};

struct queue* init_queue();
struct TCB_t* dequeue( struct queue*);
void enqueue( struct queue* ,  struct TCB_t* );
void rotate( struct queue*, int);
void print_q( struct queue*);
struct TCB_t* new_item();

#endif
