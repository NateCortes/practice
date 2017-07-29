#ifndef NODE_H
#define NODE_H

struct node{
  int data, height;
  struct node *left, *right;
};

struct AVL_tree{
  struct node* root;
};

struct node* gen_n( int data){
  
struct node* pass = ( struct node*) malloc( sizeof( struct node));
  pass->data = data;
  pass->left = pass->right = NULL;
  
  return pass;
}

struct AVL_tree* gen_avl( struct node* root){
  struct AVL_tree* pass = ( struct AVL_tree*) malloc( sizeof( struct AVL_tree));
  pass->root = root;

  return pass;
} 

#endif
