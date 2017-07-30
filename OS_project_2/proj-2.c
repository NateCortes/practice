#include <stdio.h> 
#include <string.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>

#include "queue.h"

static struct queue *run_q;//ready queue for context swapping

#include "threads.h"
#include "semaphore.h"

static struct semaphore* sea;
static int count;

void func1();
void func2();

int main(){
  /*
   V() increments the semaphore, and should be called at the end of a process requiring mutual exclusion
   P() decrements the semaphore, blocking the queue
   */
  run_q = init_queue();
  sea = gen_s();
  count = 0;

  init_s( sea, 1);

  printf( "%i\n", sea->val);
  
  start_thread( func1);
  start_thread( func2);
  
  run();

  return 0;
}


void func1( ){
  //thread 1 for use with semaphores
  int i = 1;
  while( i > 0){
    P( sea);
    
    count++;
    while( i < 60000){
      printf( "\rthread 1, count: %i", count);
      i++;
    }
    
    i = 1;

    V( sea);
    yeild();
  }
  
}

void func2( ){
  //thread 2 used with semaphores

  int i = 1;
  while( i > 0){
    P( sea);
    
    count++;
    while( i < 60000){
      printf( "\rthread 2, count: %i", count);
      i++;
    }
    
    i = 1;
    V( sea);
    yeild();
  }

}
