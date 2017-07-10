#ifndef TCB_H
#define TCB_H
#include <ucontext.h>
#include <signal.h>
#include <string.h>

#define MEMORY 1024

typedef struct TCB_t{
  int data;
  ucontext_t    context;

  struct TCB_t* next;
  struct TCB_t* prev;

} TCB_t;

//void init_TCB( TCB_t *tcb, void *function, void *stackP, int stack_size);
/*
void test_TCB( TCB_t *tcb){
  getcontext( &tcb->context);
  tcb->context.uc_stack.ss_sp = MEMORY;
  tcb->context.uc_stack.ss_size = SIGSTKSZ;
  printf( "stack pointer for context: %d\n", tcb->context.uc_stack.ss_sp);
  printf( "stack size for context: %d\n",(int) tcb->context.uc_stack.ss_size);
 //printf( "%d, %d, %d", tcb.context->ss_sp, tcb.context->ss_size, tcb.context->ss_flags);
}*/

void init_TCB( TCB_t *tcb, void *function, void *stackP, int stack_size){
  
  memset( tcb, '\0', sizeof( TCB_t));
  getcontext( &tcb->context);
  
  tcb->context.uc_stack.ss_sp = stackP;
  tcb->context.uc_stack.ss_size = (size_t) stack_size;

  makecontext( &tcb->context, function, 0); 
}
#endif
