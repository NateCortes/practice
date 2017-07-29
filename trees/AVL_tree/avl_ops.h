#ifndef AVL_OPS_H
#define AVL_OPS_H

#include "rotations.h"

int calc_balance( struct node*);
struct node* search( struct node*, int);
struct node* insert( struct node*, int);
struct node* remove( struct node*, int);
struct node* find_predeccessor( struct node*);

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
  }

  // std::cout<< "found the node"<<std::endl;
  if( done->right && done->left){
    // std::cout<< "it's not alone"<<std::endl;
    //swap all data values with done's predeccessor
    struct node* succ = find_predeccessor( done->left);
    
    done->data = succ->data;
    
    done->left = remove( done->left, done->data);
  }else{
    // std::cout<< "it has one or less children"<<std::endl;
    // struct node* hold = done->right ? done->right : done->left;
    struct node* hold = NULL;
    if( done->right){
      hold = done->right;
    }else{
      hold = done->left;
    }
 
   // std::cout<< "done exists"<<std::endl;
    if( hold == NULL){
      hold = done;
      done = NULL;
    } 
    // std::cout<< "deleting the node"<<std::endl;
    delete hold;
  }
  // std::cout<< "calculating height"<<std::endl;
  if( done == NULL){ 
    return done;
  }

    done->height = calc_height( done);
    // std::cout<< "done calculating height"<<std::endl;
  int bal = calc_balance( done);
  //std::cout<<"checking balance"<<std::endl;
  if( bal > 1 ){
    //left tree imbalance    
    if( val < done->left->data){
      return rotate_right( done);
    }else if( val > done->left->data){
      done->left = rotate_left( done->left);
      return rotate_right( done);
    }
  }
  
  if( bal < -1){
    //right tree imbalance
    if( val > done->right->data){
      return rotate_left( done);
    }else if( val < done->right->data){
      done->right = rotate_right( done->right);
      return rotate_left( done);
    }
  }

  return done;
}

struct node* find_predeccessor( struct node* doe){
  
  if( doe->right == NULL && doe->left == NULL){
    return doe;
  }

  return find_predeccessor( doe->right);
}

#endif
