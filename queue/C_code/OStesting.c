#include <stdio.h> 
#include <string.h>
#include <signal.h>

void func1();
void func2();
void sect_wrap( void (*)());
static struct queue *run_q;

#include "threads.h"

int main(){
  
  struct TCB_t *mcarthur = new_item();
  struct TCB_t *jackson = new_item();
  //test_TCB( mcarthur);
  //init_TCB( jackson, func1, MEMORY, SIGSTKSZ);

  run_q = init_queue();
  printf( "address of run_q: %d\n", run_q);

  printf( "\n|------------\n");
  start_thread( func1);
  print_q( run_q);
  printf( "\n------------|\n");

  sect_wrap( run);

  sect_wrap( yeild);
  
   return 0;
}

void func1( ){
  //dummy function 1 for use with context switching
  printf( "it's just a function...\n");
}

void func2( ){
  //dummy function 2 for use with context switching
  printf( "...it's a function");
}

void sect_wrap( void (*func)()){
  printf( "\n|---------------\n");
  func();
  printf( "\n---------------|\n");
}
