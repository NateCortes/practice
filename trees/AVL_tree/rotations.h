#ifndef ROTATIONS_H
#define ROTATIONS_H

struct node* rotate_left( struct node*, struct node*);
struct node* rotate_right( struct node*, struct node*);
int calc_height( struct node*);

struct node* rotate_left( struct node* node){
  
  struct node* y = node->right;
  struct node* s = y->left;

  y->left = node;
  node->right = s;
  
  node->height = calc_height( node);
  y->height = calc_height( y);

  return y;
}

struct node* rotate_right( struct node* node){
  
  struct node* y = node->left;
  struct node* s = y->right;

  y->right = node;
  node->left = s;

  node->height = calc_height( node);
  y->height = calc_height( y);

  return y;
}

int calc_height( struct node* node){
  if( node == NULL){
    return -1;
  }

  int lh = calc_height( node->left);
  int rh = calc_height( node->right);

  if( lh > rh){
    return 1 + lh;
  }else{
    return 1 + rh;
  }
  
}

#endif
