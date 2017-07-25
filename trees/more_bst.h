#ifndef MORE_BST_H
#define MORE_BST_H

#include <algorithm>

int height( struct node*);
struct node* delete_tree( struct node*);

struct node* delete_tree( struct node* root){
  //recursively deletes a tree
  if( root == NULL){
    return NULL;
  }

  root->left = delete_tree( root->left);
  root->right = delete_tree( root->right);

  delete root;

  return NULL;
}

int height( struct node* root){
  //returns the height of the maximum path of a tree
  if( root == NULL){
    return 0;
  }
  
  int lh = height( root->left);
  int rh = height( root->right);

  if( lh > rh){
    return 1 + lh;
  }else{
    return 1 + rh;
  }

}

#endif
