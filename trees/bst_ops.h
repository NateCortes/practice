#ifndef BST_OPS_H
#define BST_OPS_H

void inorder( struct node*);
void preorder( struct node*);
void postorder( struct node*);
void travel_wrapper( void (*)( struct node*), struct node*);

struct node* insert( struct node*, struct node*);
struct node* find( struct node*, int);

//Print Traversals////////////////

void inorder( struct node* root){

  if( root == NULL){
    return;
  }

  inorder( root->left);
  std::cout<<root->data<<" ";
  inorder( root->right);

}

void preorder( struct node* root){

  if( root == NULL){
    return;
  }

  std::cout<<root->data<<" ";
  preorder( root->left);
  preorder( root->right);
  
}

void postorder( struct node* root){

  if( root == NULL){
    return;
  }

  postorder( root->left);
  postorder( root->right);
  std::cout<<root->data<<" ";

}

void travel_wrapper( void (*func)( struct node*), struct node* node){
  func( node);
  std::cout<<std::endl;
}

/////////////////////////////////

//Basic Operations ( find, insert, delete)/////

struct node* insert( struct node* root, struct node* ins){

  if( root == NULL){
    return ins;
  }else{
    ins->parent = root;
    if( ins->data > root->data){
      root->right = insert( root->right, ins);
    }else{
      root->left = insert( root->left, ins);
    }
  }
  
  return root;
}

struct node* find( struct node* root, int key){
 
  if( root == NULL){
    return NULL;
  }

  if( key > root->data){
    return find( root->right, key);
  }else if( key < root->data){
    return find( root->left, key);
  }

  return root;
}

///////////////////////////////////////////////
#endif
