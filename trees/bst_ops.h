#ifndef BST_OPS_H
#define BST_OPS_H

struct node* find( struct node*, int);
struct node* insert( struct node*, struct node*);
void remove( struct node*, int);
void nullify( struct node*);
int num_children( struct node*);
struct node* predecessor( struct node*);

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

void remove( struct node* root, int data){
  struct node* node = find( root, data);
  if( node){
    int child = num_children( node);
    // std::cout<< "deleting node with "<< child<< " children"<<std::endl;
    switch( child){
    case 0:
      nullify( node);
      delete node;
      break;
    case 1:
      if( node->right != NULL){
	node->right->parent = node->parent;
	if( node == node->parent->left){
	  node->parent->left = node->right;
	}else{
	  node->parent->right = node->right;
	}
      }else{    
	node->left->parent = node->parent;
	if( node == node->parent->left){
	  node->parent->left = node->left;
	}else{
	  node->parent->right = node->left;
	}
      }

      delete node;
      break;
    case 2:
      struct node* pre = predecessor( node->left);
      std::cout<< "predecessor: "<< pre->data<<std::endl;
      //swap all data values, nullify pointers to and delete pre
      node->data = pre->data;
      
      nullify( pre);
            
      delete pre;
      break;
    }
     
  }
}

void nullify( struct node* node){
  //helper method for deleting a node 
  //sets the parent pointer pointing to this node to NULL
  if( node->parent){
    if( node == node->parent->left){
      node->parent->left = NULL;
    }else{
      node->parent->right = NULL;
    }
  }else{
    std::cout<< "attempting to nullify root"<<std::endl;
  }
}

struct node* predecessor( struct node* node){
  //finds the predecessor of the node
  //largest valued node less than current node
  if( node->right == NULL && node->left == NULL){
    return node;
  }
  
  predecessor( node->right);
}

int num_children( struct node* node){
  //returns the number of children within a node
  //used inside delete method
  int num = 0;

  if( node->left){
    num++;
  }

  if( node->right){
    num++;
  }
  
  return num;
}
///////////////////////////////////////////////
#endif
