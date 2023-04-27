#include <iostream>
using namespace std;

//creating a structure for a node in the binary search tree
struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) { 
        traverseInOrder(root->left); 
        cout << root->key << " "; 
        traverseInOrder(root->right); 
    } 
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if (node == NULL){
    struct node* temp = new struct node; //allocating memory for the new node
    temp->key = key;
    temp->left = temp->right = NULL;
    node= temp;
    return node;
  }

  //if the value is greter thn the current node
  if (key > node->key){
      node->right=insertNode(node->right , key);
    }

  //if the value is lesser than the current node
  else if (key < node->key){
    node->left=insertNode(node->left , key);
  }

  //if the node value is already excisting then do nothing
  else if (key == node->key){
    ;
  }
  return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root==NULL){
    return NULL;
  }

  //if the value which needed to be deleted is lesser than value at current node then search left sub binary search tree
  else if(key < root->key){
    root->left= deleteNode(root->left , key);
  }

  //if the value which needed to be deleted is greater than value at current node then search right sub binary search tree
  else if (key > root->key){
    root->right = deleteNode(root->right , key);
  }

  else if (key == root->key){
    //if both child BST are null
    if (root->left==NULL && root->right==NULL){
      delete root;
    }

    //if left child is null
    else if(root->left==NULL){
      struct node *temp = root;
      root = root->right;
      delete temp;
    }

    //if right child is null
    else if (root->right==NULL){
      struct node *temp = root;
      root = root->left;
      delete temp;
    }

    //if both right and left children are not null
    else{
      struct node *temp = root->right;
      while (temp->left != NULL){
        temp = temp->left;
      } 
      root->key = temp->key;
      delete temp;
      root->right = deleteNode(root->right , temp->key);
    }
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
