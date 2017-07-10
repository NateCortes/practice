#include <stdio.h>
#include "queue.h"

void run();
void yeild();
void start_thread( void (*)());

void start_thread( void (*func)()){

  //allocate a stack
  printf( "allocating stack\n");
  int *stack = (int*) malloc( SIGSTKSZ);
  //allocate a TCB
  printf( "creating a tcb\n");
  struct TCB_t *create = new_item();
  //call init_TCB
  printf( "initializing tcb\n");
  init_TCB( create, func, stack, SIGSTKSZ);
  //call addQ
  printf( "adding to ready queue\n");
  enqueue( run_q, create);
}

void run(){
  ucontext_t parent;
  printf( "getting context\n");
  getcontext( &parent);
  
  printf( "swapping context\n");
  swapcontext( &parent, &( run_q->head->context));
}

void yeild(){
  ucontext_t parent;
  getcontext( &( run_q->head->context));

  //rotate queue
  printf( "rotating queue\n");
  rotate( run_q, 0);
  //swap context
  printf( "swapping context\n");
}



