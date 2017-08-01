#ifndef AVL_OPS_H
#define AVL_OPS_H

#include "rotations.h"

int calc_balance( struct node*);
struct node* search( struct node*, int);
struct node* insert( struct node*, int);
struct node* remove( struct node*, int);
struct node* find_predeccessor( struct node*);

void delete_avl_tree( struct AVL_tree*);

struct node* search( struct node* eon, int val){
 
  if( eon == NULL){
    return NULL;
  }
  
  if( val > eon->data){
    return search( eon->right, val);
  }else if( val < eon->data){
    return search( eon->left, val);
  }
  
  return eon;
}

struct node* insert( struct node* don, int val){
  if( don == NULL){
    return gen_n( val);
  }
  
  if( val > don->data){
    don->right = insert( don->right, val);
  }else if( val < don->data){
    don->left = insert( don->left, val);
  }
  
  don->height = calc_height( don);

  int bal = calc_balance( don);

  if( bal > 1 ){
    //left tree imbalance    
    if( val < don->left->data){
      return rotate_right( don);
    }else if( val > don->left->data){
      don->left = rotate_left( don->left);
      return rotate_right( don);
    }
  }
  
  if( bal < -1){
    //right tree imbalance
    if( val > don->right->data){
      return rotate_left( don);
    }else if( val < don->right->data){
      don->right = rotate_right( don->right);
      return rotate_left( don);
    }
  }

  return don;
}

int calc_balance( struct node* nod){
  int lh = 0;
  int rh = 0;
  
  if( nod->left){
    lh = nod->left->height;
  }
  
  if( nod->right){
    rh = nod->right->height;
  }

  return ( lh - rh);
}

struct node* remove( struct node* done, int val){

  if( done ==  NULL){
    return NULL;
  }

  if( val > done->data){
    done->right = remove( done->right, val);
  }else if( val < done->data){
    done->left = remove( done->left, val);
  }else{

    // std::cout<< "found the node"<<std::endl;
    if( (done->right == NULL) || (done->left == NULL)){
      struct node* hold = done->left ? done->left : done->right;
      
      if( hold == NULL){
	hold = done;
	done = NULL;
      }else{
	done->data = hold->data;
	done->left = hold->left;
	done->right = hold->right;
      }
      
      delete hold;

    }else{
      struct node* pred = find_predeccessor( done->left);
      
      done->data = pred->data;
      
      done->left = remove( done->left, done->data);
      
    }
  }
  // std::cout<< "calculating height"<<std::endl;
  if( done == NULL){ 
    return done;
  }

  done->height = calc_height( done);
 
  int bal = calc_balance( done);
 
  if( bal > 1 ){
    //left tree imbalance    
    if( calc_balance( done->left) < 0){
      done->left = rotate_left( done->left);
      return rotate_right( done);
    }else if( calc_balance( done->left) >= 0){
      return rotate_right( done);
    }
  }
  
  if( bal < -1){
    //right tree imbalance
    if( calc_balance( done->right) > 0){
      done->right = rotate_right( done->right);
      return rotate_left( done);
    }else if( calc_balance( done->right) <= 0){
      return rotate_left( done);
    } 
  }

  return done;
}

struct node* find_predeccessor( struct node* doe){
  //finds the maximum value in a tree ( doesn't find the predecessor all on its own!)
  if( doe->right == NULL){
    return doe;
  }

  return find_predeccessor( doe->right);
}

void delete_avl_tree( struct AVL_tree* tree){
  do{
    tree->root = remove( tree->root, tree->root->data);
  }while( tree->root != NULL);
}

#endif
