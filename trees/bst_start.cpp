#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "bst_struct.h"
#include "bst_ops.h"

int main(){
  
  struct node* test_root = gen_node( 100);
  check_node( test_root);
  std::cout<<"root address: "<< test_root<<std::endl;
  insert( test_root, gen_node( 1000));
  insert( test_root, gen_node( 10));
  insert( test_root, gen_node( 500));
  insert( test_root, gen_node( 5000));
  insert( test_root, gen_node( 5));
  insert( test_root, gen_node( 50));
  check_node( test_root);

  std::cout<< "found: ";
  int key = 1000;
  check_node( find( test_root, key));
 
  travel_wrapper( &inorder, test_root); 

  return 0;
}
