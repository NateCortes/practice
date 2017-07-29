#ifndef ROTATIONS_H
#define ROTATIONS_H

void rotate_left( struct node*, struct node*);
void rotate_right( struct node*, struct node*);

void rotate_left( struct node* node, struct node* root){

  struct node* pnt = node->parent;

  if( pnt == root){
    std::cout<< "this is the root"<<std::endl;
    
    check_node( root);
    root = node;
    node->parent = NULL;
    std::cout<< "this is the new root"<<std::endl;
    check_node( root);
    check_node( root->left);
  }

  if( pnt->parent){
    node->parent = pnt->parent;
    if( node->parent == pnt->parent->left){
      pnt->parent->left = node;
    }else{
      pnt->parent->right = node;
    }
    
  }else{
    node->parent = NULL;
  }
  
  pnt->parent = node;
  pnt->right = node->left;
  node->left = pnt;

}


void rotate_right( struct node* node, struct node* root){

  struct node* pnt = node->parent;
  
  if( pnt->parent){
    node->parent = pnt->parent;
  }

  if( pnt == pnt->parent->left){
    pnt->parent->left = node;
  }else{
    pnt->parent->right = node;
  }

  pnt->parent = node;
  pnt->left = node->right;
  node->right = pnt;
  
}

#endif
