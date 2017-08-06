#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

void reverse( string *pass);
void swap( char* a, char* b);

int main(){

  string *phrase = new string ("the clock strikes twelve, and all is well");
 
  cout<< *phrase<<endl;

  reverse( phrase);
  
  cout<< *phrase<<endl;

  delete phrase;
  
  return 0;
}

void reverse( string *pass){
  int red = 0;
  int blue = pass->size() - 1;

  do{
    
    swap( pass->at( red), pass->at( blue));
    red++;
    blue--;
    
  }while( red < blue);
  
}

void swap( char* a, char* b){
  char *temp = a;
  a = b;
  b = a;  
}
