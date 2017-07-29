#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <fstream>

#include "bst_struct.h"
#include "bst_trav.h"
#include "bst_ops.h"
#include "more_bst.h"

struct Tree{
  struct node* ROOT;
};

int main(){
  FILE* librarian = fopen( "level_order.txt", "r");
  int read;

  fscanf( librarian, "%i", &read);
  struct node* test_root = gen_node( read);
  struct Tree* balance = ( struct Tree*) malloc( sizeof( struct Tree));
  insert( test_root, gen_node( 50));
  insert( test_root, gen_node( 200));
  insert( test_root, gen_node( 150));
  insert( test_root, gen_node( 500));
  insert( test_root, gen_node( 600));

  std::cout<<"root address: "<< test_root<<std::endl;
  
  /* check_node( test_root);*/
  

  while( !feof( librarian)){
    fscanf( librarian, "%i", &read);
    //std::cout<< read<<std::endl;
    insert( test_root, gen_node( read));
  }
  check_node( test_root);

  
  /*
 std::cout<< "found: ";
  int key = 5000;
  check_node( find( test_root, key));
  
  // print_path( test_root, 3700);

  
  std::cout<< "removing... "<<std::endl;
  remove( test_root, key);
  remove( test_root, 1000);
  remove( test_root, 10);
  */
  
  std::cout<<"height of tree, "<< height( test_root)<<std::endl;
  std::cout<< "height of left and right subtrees "<< height( test_root->left)<< ", "<< height( test_root->right)<<std::endl;

  // test_root = delete_tree( test_root);
  return 0;
}
