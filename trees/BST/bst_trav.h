#ifndef BST_TRAV_H
#define BST_TRAV_H

void inorder( struct node*);
void preorder( struct node*);
void postorder( struct node*);
void print_path( struct node*, int);
void travel_wrapper( void (*)( struct node*), struct node*);

//Traversals////////////////

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

void print_path( struct node* root,  int data){
  if( root->data == data){
    std::cout<< root->data<<std::endl;
    return;
  }
  
  std::cout<< root->data<<" ";
  
  if( root->data < data){
    print_path( root->right, data);
  }else{
    print_path( root->left, data);
  }
  
}

void travel_wrapper( void (*func)( struct node*), struct node* node){
  //convenience method taking function pointer as input
  //wraps traversal and appends a '\n' to end of traversal output
  std::cout<<"[ ";
  func( node);
  std::cout<< "]"<<std::endl;
  
}

/////////////////////////////////

#endif
