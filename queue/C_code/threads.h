#include <stdio.h>
#include "queue.h"

void run();
void yeild();
void start_thread( void (*)());
ucontext_t parent;
void start_thread( void (*func)()){

  //allocate a stack  
  printf( "allocating stack, ");
  void *stack = (void*) malloc( SIGSTKSZ);
  //allocate a TCB
  printf( "creating a tcb, ");
  struct TCB_t *create = new_item();
  //call init_TCB
  printf( "initializing tcb, ");
  init_TCB( create, func, stack, SIGSTKSZ);
  //call addQ
  printf( "adding to ready queue\n");
  enqueue( run_q, create);
}

void run(){
  //  ucontext_t parent;
  printf( "getting context, ");
  getcontext( &parent);
  
  printf( "swapping context\n");
  swapcontext( &parent, &( run_q->head->context));
}

void yeild(){
  //ucontext_t parent = run_q->head->context;

  //rotate queue
  printf( "rotating queue, ");
  rotate( run_q, 0);
  //swap context
  printf( "swapping context\n");
  // swapcontext( &parent, &( run_q->head->context));
  setcontext( &( run_q->head->context));
  // setcontext( &parent);
}



