#include "queue.h"
/*
  Author: Nate Cortes
  Purpose: Circular Queue operations for CSE 330 ( Operating Systems)
 */
struct queue* init_queue(){
  //initializes queue structure
  struct queue* q = (struct queue*) malloc( sizeof( struct queue));
  q->head = NULL;
  q->tail = q->head;
  q->size = 0;
  
  return q;
}

struct TCB_t* new_item( ){
  //initializes TCB_t struct for queue
  struct TCB_t* pass = malloc( sizeof( struct TCB_t));
  pass->next = NULL;
  pass->prev = NULL;
  pass->data = 0;

  return pass;
}

void enqueue( struct queue* qu, struct TCB_t* add){
  if( add){
    if( qu->head == NULL && qu->size == 0 ){
      // printf( "adding to empty queue\n");
      qu->head = qu->tail = add;
      qu->head->next = qu->head->prev = add;
      qu->tail->next = qu->tail->prev = add;
    }else{
      // printf( "adding to populated queue\n");
      add->prev = qu->tail;
      add->next = qu->head;
      qu->tail->next = add;
      qu->head->prev = add;

      qu->tail = add;     
    }

    qu->size++; //counts size of queue
  }else{
    printf( "error adding element");
  }
}

struct TCB_t* dequeue( struct queue* qu){
  struct TCB_t* pass = NULL; //will return NULL if queue is empty
  
  if( qu->head != NULL && qu->size > 0){

    pass = qu->head;  

    qu->head = qu->head->next;
    qu->head->prev = qu->tail;
    qu->tail->next = qu->head;
    
    if( qu->size == 1){ //resets the queue when final element was dequeue'd
      qu->head = qu->tail = NULL;
    }
    
    qu->size--; //counts size
  }else{
    printf( "queue empty");
  }

  return pass;
}

void rotate( struct queue* qu, int dir){
  //rotates the queue left or right by swapping pointers
  switch( dir){
  case 1://rotate right
    qu->head = qu->head->prev;
    qu->tail = qu->tail->prev;
    break;
  case 0://rotate left
    qu->head = qu->head->next;
    qu->tail = qu->tail->next;
    break;
  default:
    printf( "function must take 1 or 0");
  }
}

void print_q( struct queue* qu){
  struct TCB_t* point = qu->head;
  printf( "[ ");
  if( point){
    while( point != qu->tail){
      printf("%d ", point->data);
      point = point->next;
    }
    
    printf( "%d ", point->data);
    
  } 
  printf( "]\n");
}
