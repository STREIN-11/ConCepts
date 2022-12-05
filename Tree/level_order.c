#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* left,*right;
};
void level(struct Node* root,int data);
int height(struct Node* root);
struct Node* newnode(int data);

void printlevel(struct Node* root){
    int h = height(root);
    for (int i = 1; i <= h; i++){
        level(root,i);
    }
}

void level(struct Node* root,int data){
    if(root==NULL)
        return;
    if(data==1)
        printf("%d",root->data);
    else if (data>1){
        level(root->left,data-1);
        level(root->right,data-1);  
    }
}

int height(struct Node* root){
    if(root==NULL)
        return 0;
    else{
        int lheight = height(root->left);
        int rheight = height(root->right);
        if(lheight>rheight)
            return (lheight+1);
        else
            return (rheight+1);
    }
}
struct Node* newnode(int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node*));
    new->data = data;
    new->left = new->right = NULL;
    return (new);
}

int main(int argc, char const *argv[]){
    struct Node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    printf("Result : ");
    printlevel(root);

return 0;
}
