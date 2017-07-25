#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <fstream>

#include "bst_struct.h"
#include "bst_trav.h"
#include "bst_ops.h"
#include "more_bst.h"

int main(){
  FILE* librarian = fopen( "level_order.txt", "r");
  int read;

  fscanf( librarian, "%i", &read);
  struct node* test_root = gen_node( read);
  check_node( test_root);
  std::cout<<"root address: "<< test_root<<std::endl;

  while( !feof( librarian)){
    fscanf( librarian, "%i", &read);
    //std::cout<< read<<std::endl;
    insert( test_root, gen_node( read));
  }
  check_node( test_root);

  

  std::cout<< "found: ";
  int key = 5000;
  check_node( find( test_root, key));
  
  print_path( test_root, 3700);

  /*
  std::cout<< "removing... "<<std::endl;
  remove( test_root, key);
  remove( test_root, 1000);
  remove( test_root, 10);
  */
  
  std::cout<<"height of tree, "<< height( test_root)<<std::endl;
  std::cout<< "height of left and right subtrees "<< height( test_root->left)<< ", "<< height( test_root->right)<<std::endl;

  // test_root = delete_tree( test_root);
  
  travel_wrapper( &inorder, test_root); 
  travel_wrapper( &preorder, test_root);
  travel_wrapper( &postorder, test_root);
  
  remove( test_root, key);
  
  travel_wrapper( &inorder, test_root);
  
  return 0;
}
