#ifndef TCB_t_H
#define TCB_t_H
//#include <stdio.h>
#include <ucontext.h>
////////////////////////
#include <string.h>
////////////////////////


//void init_TCB( TCB_t*, void*, void*, int);

typedef struct TCB_t{
  int data;
  ucontext_t    context;

  struct TCB_t* next;
  struct TCB_t* prev;

} TCB_t;
/*
void init_TCB ( TCB_t *tcb, void *function, void *stackP, int stack_size){
  
  memset( tcb, '\0', sizeof( TCB_t));
  getcontext( &tcb->context);
  
  tcb->context.uc_stack.ss_sp = stackP;
  tcb->context.uc_stack.ss_size = (size_t) stack_size;

  makecontext( &tcb->context, function, 0);
  
  }*/

#endif
