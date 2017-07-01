#include "stack.h"

stack::stack(){
  std::cout<<"making a stack"<<std::endl;
  head = NULL;
}

void stack::push( element* add){ 
  if( add){
    if( head == NULL && size == 0){ //adds first element
      head = add;
    }else{                //puts element on top of stack
      add->next = head;
      head = add;
    }
    size++;
  }  
}

void stack::pop( ){
  if( head != NULL && size > 0){
    //so long as there are elements in the queue
    struct element* temp = head;
    
    //shuffles pointers around to remove head element
    head = head->next;
    
    std::cout<<"popping: "<<temp->data<<std::endl;

    //resets the head pointer when removing last element
    if( size == 1){
      head = NULL;
    }
    
    size--;
    free( temp);
  }else{
    std::cout<<" stack empty"<<std::endl;
  }
}

void stack::print(){
  //prints element data in a bracketed array format
  struct element* point = head;
  std::cout<<"[ ";
  if( point){ //nothing printed if point does not exist
    while( point != NULL){
      std::cout<<point->data<<" ";
      point = point->next;
    }
  }
  std::cout<<"]"<<std::endl;
}

int stack::size_of(){
  return size;
}
