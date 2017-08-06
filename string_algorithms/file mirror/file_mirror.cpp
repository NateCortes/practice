#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

void reverse( string *pass);
void swap( char *a, char *b);

int main(){

  stack< string> S;
  string *data = new string();
  string *atad = new string();
  
  fstream file( "alice.txt", ios::in | ios::out | ios::app);
  
  if( file.is_open()){
    while( getline( file, *data)){
      cout<< *data<<endl;
      S.push( *data);
    }
    
    cout<<endl;
    file<<endl;
    
    while( !S.empty()){
      *atad = S.top();
      reverse( atad);
      cout<< *atad<<endl;
      file<< *atad<<endl;
      S.pop();
    }
 
  }
  
  delete data;
  delete atad;
  file.close();
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

void swap( char *a, char *b){
  char *temp = a;
  a = b;
  b = a;
}
