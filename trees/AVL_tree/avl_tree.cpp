#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "node.h"
#include "rotations.h"
#include "bst_trav.h"
#include "avl_ops.h"

void check_node( struct node*);

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
  std::cout<< "height of tree: "<< calc_height( avl->root)+1<<std::endl;
  
  //delete root node
  avl->root = remove( avl->root, avl->root->data);
  check_node( avl->root);
  
  //delete leaf node
  avl->root = remove( avl->root, 1);
  
  //single child deletion
  avl->root = remove( avl->root, 3);

  //double child deletion
  avl->root = remove( avl->root, 50);

  delete_avl_tree( avl);
   
  travel_wrapper( &inorder, avl->root);
  travel_wrapper( &preorder, avl->root);
  travel_wrapper( &postorder, avl->root);
  std::cout<< "height of tree: "<< calc_height( avl->root)+1<<std::endl;

  return 0;
} 

void check_node( struct node* node){
  std::cout<<"[ "<<node->data<<" | l:"<< node->left<<" | r:"<< node->right<<" ]"<<std::endl;
}
