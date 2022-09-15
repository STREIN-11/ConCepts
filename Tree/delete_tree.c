#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
};
struct Node* new(int data){
    struct Node* create=(struct Node*)malloc(sizeof(struct Node));
    create->data = data;
    create->left = create->right = NULL;
}
void inorder(struct Node* root){
    if (root != NULL) {
        inorder(root->left);
        printf("%d->", root->data);
        inorder(root->right);
  }
}

struct Node* insert(struct Node* root,int data){
    if (root==NULL){
        return new(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }
    return root;   
}

struct Node *minValueNode(struct Node *node) {
  struct Node *current = node;
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

struct Node *deleteNode(struct Node *root, int key) {
  if (root == NULL) return root;
  if (key < root->data)
    root->left = deleteNode(root->left, key);
  else if (key > root->data)
    root->right = deleteNode(root->right, key);

  else {
    if (root->left == NULL) {
      struct Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct Node *temp = root->left;
      free(root);
      return temp;
    }

    struct Node *temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

int main(int argc, char const *argv[]){
    struct Node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);
    printf("Inorder traversal: ");
    inorder(root);
    printf("NULL\n");
    root = deleteNode(root,8);
    inorder(root);
    printf("NULL");

    return 0;
}