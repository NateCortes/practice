#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "node.h"
#include "rotations.h"
#include "bst_trav.h"
#include "avl_ops.h"


int main( ){
  FILE* librarian = fopen( "level_order.txt", "r");
  int read;

  fscanf( librarian, "%i", &read);

  struct node* a_root = gen_n( read);
  struct AVL_tree* avl = gen_avl( a_root);

  while( !feof( librarian) ){
    fscanf( librarian, "%i", &read);
    avl->root = insert( avl->root, read); 
  }

  travel_wrapper( &inorder, avl->root);
  travel_wrapper( &preorder, avl->root);
  travel_wrapper( &postorder, avl->root);
  std::cout<< "height of tree: "<< calc_height( avl->root)<<std::endl;

  avl->root = remove ( avl->root, 1);

   travel_wrapper( &inorder, avl->root);
  travel_wrapper( &preorder, avl->root);
  travel_wrapper( &postorder, avl->root);
  std::cout<< "height of tree: "<< calc_height( avl->root)<<std::endl;

  return 0;
} 
