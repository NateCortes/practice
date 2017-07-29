#ifndef BST_STRUCT_H
#define BST_STRUCT_h

struct node* gen_node( int);
void check_node( struct node*);

struct node{
  int data, lh, rh;
  struct node *left, *right, *parent;
};

struct BST{
  struct node* Root;
};

struct node* gen_node( int data){
  struct node* pass = (struct node*) malloc( sizeof( struct node));

  pass->data = data;
  pass->left = pass->right = pass->parent = NULL;

  return pass;
}

void check_node( struct node* elem){
  std::cout<< "( ";
  if( elem){
    std::cout<<elem->data<<", ";
    std::cout<<"l:"<<elem->left<<", r:"<<elem->right<<", ";
    std::cout<<elem->parent;
  }else{
    std::cout<<"Nothing Here";
  }
  std::cout<<" )"<<std::endl;
}

#endif
