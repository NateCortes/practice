#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include "queue.h"
#include "threads.h"

struct semaphore{
  int val;
  struct queue* q;  
};

struct semaphore* gen_s(){

  struct semaphore *pass = ( struct semaphore*) malloc( sizeof( struct semaphore));
  pass->val = 0;
  pass->q = init_queue();

  return pass;
}

void init_s( struct semaphore* shore, int val){
  shore->val = val;
}

void P( struct semaphore* shore){
  printf( "\ndecrementing semaphore\n");
  shore->val--;

  if( shore->val < 0){
    printf( "\rwaiting... \n");
    enqueue( shore->q, dequeue( run_q));
  }
  
}

void V( struct semaphore* shore){
  printf( "\nincrementing semaphore\n");
  shore->val++;
 
  if( shore->val <= 0){
    printf( "placing TCB into run queue\n");
    enqueue( run_q, dequeue(  shore->q));
    yeild();
  }

}
#endif
