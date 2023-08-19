#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};  
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}


void inorder(struct node *root) {
  if (root != NULL) {
    
    inorder(root->left);

    
    printf("%d -> ", root->key);

    
    inorder(root->right);
  }
}


struct node *insert(struct node *node, int key) {
  
  if (node == NULL) return newNode(key);

  
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}


struct node *minValueNode(struct node *node) {
  struct node *current = node;

  
  while (current && current->left != NULL)
    current = current->left;

  return current;
}


struct node *deleteNode(struct node *root, int key) {
  
  if (root == NULL) return root;

  
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    struct node *temp = minValueNode(root->right);


    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}


int main() {
	int a,b;
  struct node *root = NULL;
  printf("Enter the data to be inserted");
  scanf("%d",&a);
  root = insert(root, a);
  printf("Enter the data to be inserted");
  scanf("%d",&a);
  root = insert(root, a);
  printf("Enter the data to be inserted");
  scanf("%d",&a);
  root = insert(root, a);
  printf("Enter the data to be inserted");
  scanf("%d",&a);
  root = insert(root, a);
  printf("traversal: ");
  inorder(root);
  printf("\nEnter the data to be deleted");
  scanf("%d",&b);
  root = deleteNode(root, b);
  printf("traversal: ");
  inorder(root);
}