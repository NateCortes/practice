#include "queue.h"

struct queue* init_queue(){
  struct queue* q = (struct queue*) malloc( sizeof( struct queue));
  q->head = NULL;
  q->tail = NULL;
  q->size = 0;
  
  return q;
}

void enqueue( struct queue* qu, struct element* add){
  if( add){
    if( qu->head == NULL && qu->size == 0 ){
      printf( "adding to empty queue\n");
      qu->head = qu->tail = add;
      qu->head->next = qu->head->prev = add;
      qu->tail->next = qu->tail->prev = add;
    }else{
      printf( "adding to populated queue\n");
      add->prev = qu->tail;
      add->next = qu->head;
      qu->tail->next = add;
      qu->head->prev = add;

      qu->tail = add;     
    }

    qu->size++;
  }else{
    printf( "error adding element");
  }
}

struct element* dequeue( struct queue* qu){
  struct element* pass = NULL;
  
  if( qu->head != NULL && qu->size > 0){
    printf( "size: %d\n", qu->size);
    pass = qu->head;

    qu->head = qu->head->next;
    qu->head->prev = qu->tail;
    qu->tail->next = qu->head;
    
    if( qu->size == 1){
      qu->head = qu->tail = NULL;
    }
    
    qu->size--;
  }else{
    printf( "queue empty");
  }

  return pass;
}

void print_q( struct queue* qu){
  struct element* point = qu->head;
  printf( "[ ");
  if( point){
    while( point != qu->tail){
      printf("%d ", point->data);
      point = point->next;
    }
    
    printf( "%d ", point->data);
    
  }  printf( "]\n");
}

/*
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

void OSqueue::rotate( int dir){
  switch( dir){
  case 0:
    //rotate queue once to the right
    head = head->prev;
    tail = tail->prev;
    break;
  case 1:
    //rotate queue once to the left
    head = head->next;
    tail = tail->next;
    break;
  default:
    std::cout<<"you fucked up;function takes only 1 or 0 as input"<<std::endl;

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
*/
