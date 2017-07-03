#include <stdio.h> 
#include "queue.h"

int main(){

  int ite = 9;

   struct queue *qu = init_queue(); 
   
   print_q( qu);
   
   print_q( qu);
   int i=0;
   for( i;i < 5; i++){
     struct element *a = ( struct element*) malloc( sizeof( struct element));
     a->next = NULL;
     a->prev = NULL;
     a->data = i+1;

     enqueue( qu, a);

     print_q( qu);
   }
   struct element *sack; 

   i = 0;
   for( i; i< 5; i++){
     print_q( qu);
     printf( "%d ", dequeue( qu));

     print_q( qu);
     //printf( "%d", sack);
     
   } 
   
   //print_q( qu);

   return 0;
}
