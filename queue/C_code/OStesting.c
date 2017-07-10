#include <stdio.h> 
#include <string.h>
#include <signal.h>
#include <time.h>

void func1();
void func2();
void func3();
double program_time;
void sect_wrap( void (*)());
static struct queue *run_q;
struct pong *field;

#include "threads.h"
#include "pong.h"

int main(){
  field = init_pong();
  printf( "initial field loc: %d\n", field->loc);
  
  program_time = 0.0;
  
  srand( time( NULL));

  run_q = init_queue();
  printf( "address of run_q: %d\n", run_q);
  printf( "address of main: %d", &main);
  

  printf( "\n|------------\n");
  start_thread( func1);
  start_thread( func2);
  start_thread( func3);
  print_q( run_q);
  printf( "\n------------|\n");

  sect_wrap( run);
  
  printf( "returned to main, done!\n");
  
  return 0;
}

void func1( ){
  //dummy function 1 for use with context switching

  clock_t time = clock();
  
  int i;
  for( i = 1; i< CLOCKS_PER_SEC / 10; i++){   
    print_pong( field);
    if( i % (CLOCKS_PER_SEC /100 ) == 0){

     shift_right( field);
    }
  }
  
  time = clock() - time;
  program_time += ( (double) time / CLOCKS_PER_SEC) * 10;
  printf( " %.2f seconds\n", ((double) time / CLOCKS_PER_SEC) * 10.0);
  sect_wrap( yeild);
}

void func2( ){
  //dummy function 2 for use with context switching
  
  clock_t time = clock();
  printf( "it's just a function...\n");

  int i;
  for( i = 1; i< CLOCKS_PER_SEC / 10; i++){   
    print_pong( field);
    if( i % (CLOCKS_PER_SEC /100 ) == 0){

     shift_left( field);
    }
  }
 
  time = clock() - time;
  program_time += ( (double) time / CLOCKS_PER_SEC) * 10;
  printf( " %.2f seconds\n", ((double) time / CLOCKS_PER_SEC) * 10.0);
  
  sect_wrap( yeild);
}

void func3( ){
  //dummy function 3 for use with context switching 
  clock_t sometime = clock();
  time( &sometime);
  printf(  "current time, %s", ctime( &sometime));
  yeild();
}

void sect_wrap( void (*func)()){
  printf( "\n|---------------\n");
  func();
}
