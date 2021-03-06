#ifndef TCB_H
#define TCB_H
#include <ucontext.h>
#include <signal.h>
#include <string.h>

/*
  Author: Nate Cortes
  Purpose: Thread Control Block data structure and initialization method
 */

typedef struct TCB_t{
  int data;//tag identifier
  ucontext_t    context;

  struct TCB_t* next;
  struct TCB_t* prev;

} TCB_t;

void init_TCB( TCB_t *tcb, void *function, void *stackP, int stack_size){;
  memset( tcb, '\0', sizeof( TCB_t));
  tcb->data = (int) (rand( NULL) % 1000); //tag identifiying item in queue
  getcontext( &tcb->context);
  
  tcb->context.uc_stack.ss_sp = stackP;
  tcb->context.uc_stack.ss_size = (size_t) stack_size;

  makecontext( &tcb->context, function, 0); 
}
#endif
