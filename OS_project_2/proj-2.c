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

void func1();
void func2();

//#include "pong.h"

int main(){
  /*
   V() increments the semaphore, and should be called at the end of a process requiring mutual exclusion
   P() decrements the semaphore, blocking the queue
   */
  run_q = init_queue();
  sea = gen_s();
  
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

    printf( "thread 1\n");

    V( sea);

    yeild();
  }
  
}

void func2( ){
  //thread 2 used with semaphores

  int i = 1;
  while( i > 0){
    P( sea);

    printf( "thread 2\n");

    V( sea);

    yeild();
  }

}
