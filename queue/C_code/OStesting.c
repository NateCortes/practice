#include <stdio.h> 
#include "queue.h"

int main(){

  int ite = 9;

   struct queue *qu = init_queue(); 
   
   print_q( qu);
  
   int i=0;
   for( i;i < 5; i++){
     struct TCB_t *a = new_item();
     a->data = i+1;

     enqueue( qu, a);

     print_q( qu);
   }

   i=0;
   for( i; i<3;i++){
     rotate( qu, 0);
     print_q( qu);
   }

   struct TCB_t* point;

   i = 0;
   for( i; i< 5; i++){
     free( qu->head);
     point = dequeue( qu);
     print_q( qu);
     printf( "removed: %d\n", point); 
     //free( point);
     printf( "removed: %d\n", point->data);
     
   } 

   return 0;
}
