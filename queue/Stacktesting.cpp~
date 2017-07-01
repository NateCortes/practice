#include <stdlib.h> 
#include <iostream>
#include "element.h"
#include "queue.h"

using namespace std;

class OSqueue;

int main(){

  OSqueue *stein = new OSqueue();
  int ite = 100;
  
  stein->print();

 for( int i = 0; i < ite; i++ ){
   struct element *add = ( struct element*) malloc( sizeof( struct element));
   add->next = NULL;
   add->prev = NULL;
   add->data = i;

    stein->enqueue( add);
     stein->print();
 }
  
 for( int i = 0;i < ite; i++ ){
   stein->dequeue();
   stein->print();
 }

   return 0;
}
