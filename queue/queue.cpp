#include "queue.h"

OSqueue::OSqueue(){
  std::cout<<"making a queue"<<std::endl;
  head = NULL;
  tail = NULL;
}

void OSqueue::enqueue( element* add){ 
  if( add){
    if( head == NULL && size == 0){ //adds first element
      head = tail = add;
      head->next = tail;
      head->prev = tail;
    }else{                //adds element in a populated queue
      add->next = head;
      add->prev = tail;
      tail->next = add;
      head->prev = add;
      tail = add;
    }
    size++;
  }  
}

void OSqueue::dequeue( ){
  if( head != NULL && size > 0){
    //so long as there are elements in the queue
    struct element* temp = head;
    
    //shuffles pointers around to remove head element
    head->prev->next = head->next;
    head = head->next;
    head->prev = tail;
    
    std::cout<<temp->data<<std::endl;

    //resets the head and tail pointers when removing last element
    if( size == 1){
      head = NULL;
      tail = NULL;
    }
    
    size--;
    free( temp);
  }else{
    std::cout<<" queue empty"<<std::endl;
  }
}

void OSqueue::print( ){
  //prints element data in a bracketed array format
  struct element* point = head;
  std::cout<<"[ ";
  if( point){ //nothing printed if point does not exist
    while( point != tail){
      std::cout<<point->data<<" ";
      point = point->next;
    }
    if( point == tail){  //prints last element 
      std::cout<< point->data<<" ";
    }
  }
  std::cout<<"]"<<std::endl;
}

int OSqueue::size_of( ){
  return size;
}
