#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* new(int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
}
void inorder(struct Node* new){
    if (new == NULL)
        printf("NULL");
    inorder(new->left);
    printf("%d",new->data);
    inorder(new->right);
}


int main(int argc, char const *argv[]){
    struct Node* root = new(10);
    root->left = new(20);
    root->right = new(30);
    root->left->left = new(40);
    root->left->right = new(50);

    return 0;
}
