#include <stdlib.h>
#include <iostream>
/* 
   simple Command Line waiting animation
 */

int main( ){
  int i = 0;
  nit j = 1;
  

  while( j > 0){
    if( i < 60000){
      printf( "\rwaiting ");
    }else if( 60000<= i && i<120000){
      printf( "\rwaiting. ");
    }else if( 120000<= i && i <180000){
      printf( "\rwaiting. .");
    }else if( 180000<= i && i <240000){
      printf( "\rwaiting. . .");
    }else if( i > 240000){ 
      printf( "\rwaiting           ");
      i = 0;      
    }
   
    i++;
  }
  return 0;
}
