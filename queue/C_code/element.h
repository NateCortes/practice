#ifndef TCB_t_H
#define TCB_t_H
//#include <stdio.h>

typedef struct TCB_t{
  int data;

  struct TCB_t* next;
  struct TCB_t* prev;

};

#endif
