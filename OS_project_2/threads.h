#ifndef THREADS_H
#define THREADS_H

#include <stdio.h>
#include <ucontext.h>
#include "queue.h"

/*
  Author: Nate Cortes
  Purpose: Thread control methods, initializing a thread to a queue, starting threads and swapping out threads.
 */

void run();
void yeild();
void start_thread( void (*)());

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
  //swaps out context of calling function with next context in Queue
  ucontext_t parent;
  printf( "getting context, ");
  getcontext( &parent);
  
  printf( "swapping context\n");
  swapcontext( &parent, &( run_q->head->context));
}

void yeild(){
  //sets the contexts to the next TCB in queue
  //rotate queue
  printf( "rotating queue, ");
  rotate( run_q, 0);
  //swap context
  printf( "swapping context\n");
  // swapcontext( &parent, &( run_q->head->context));
  setcontext( &( run_q->head->context));
}

#endif
