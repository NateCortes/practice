#include <stdlib.h> 
#include <iostream>
#include "element.h"
#include "stack.h"

using namespace std;

class stack;

int main(){

  stack *stein = new stack();
  int ite = 5;
  
  stein->print();

 for( int i = 0; i < ite; i++ ){
   struct element *add = ( struct element*) malloc( sizeof( struct element));
   add->next = NULL;
   add->prev = NULL;
   add->data = i+1;

    stein->push( add);
    stein->print();
 }
  
 for( int i = 0;i < ite; i++ ){
   stein->pop();
   stein->print();
 }

   return 0;
}
