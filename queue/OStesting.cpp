#include <stdlib.h> 
#include <iostream>
#include "element.h"
#include "queue.h"

using namespace std;

class OSqueue;

int main(){

  OSqueue *stein = new OSqueue();
  int ite = 9;
  
  stein->print();

  struct element *att = ( struct element*) malloc( sizeof( struct element));
   att->next = NULL;
   att->prev = NULL;
   att->data = 1;
   stein->enqueue( att);

 for( int i = 0; i < ite; i++ ){
   struct element *add = ( struct element*) malloc( sizeof( struct element));
   add->next = NULL;
   add->prev = NULL;
   add->data = 0;

    stein->enqueue( add);
    // stein->print();
 }

 stein->print();
 
for( int i = 0;i < ite; i++ ){
   stein->rotate( 0);
   stein->print();
 }

for( int i = 0;i < ite; i++ ){
   stein->rotate( 1);
   stein->print();
 }

 stein->print();
   return 0;
}
