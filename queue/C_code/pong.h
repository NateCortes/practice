#include <stdio.h>

typedef struct pong{
  int loc;
  int size;
  char arr[10];
}pong;

struct pong* init_pong( ){
  struct pong* new_field = ( struct pong *) malloc( sizeof(struct pong));
  new_field->loc = 0;
  new_field->size = 10;

  int i = 0;
  while( i < 10){
    if( i == 0){
      new_field->arr[ i] = '#';
    }else{
      new_field->arr[ i] = '~';
    }
    i++;
  }

  return new_field;
}

void shift_right( struct pong *field){
  if( field->loc < 9){
    field->arr[ field->loc + 1] = field->arr[ field->loc];
    field->arr[ field->loc] = '~';
    field->loc  = field->loc + 1;
  }
}

void shift_left( struct pong *field){
  if (field->loc > 0){
    field->arr[ field->loc - 1] = field->arr[ field->loc];
    field->arr[ field->loc] = '~';
    field->loc = field->loc - 1;
  }
}

void print_pong( struct pong* field){
  int i = 0;
  printf( "\r[ ");
  while( i < 10){
    printf("%c ", field->arr[ i]);
    i++;
  }
  printf( "]");
}
