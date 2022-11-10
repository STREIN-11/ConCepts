#include <stdio.h>
#include <stdlib.h>







struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int height(struct Node* root){
    if(root == NULL)
        return 0;
    return root->height;
}

int max(int a,int b){
    return (a>b)? a:b;
}

struct Node* create(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node* rightrotate(struct Node* y){
    struct Node* x = y->left;
    struct Node* t = x->right;

    x->right = y;
    y->left = t;

    y->height = max(height(y->left),height(y->right))+1;
    x->height = max(height(x->left),height(x->right))+1;
    return x;
}

struct Node* leftrotate(struct Node* x){
    struct Node* y = x->right;
    struct Node* t = y->left;

    y->left = x;
    x->right = t;

    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;
    return y;
}

int getbalance(struct Node* root){
    if(root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

struct Node* insert(struct Node* root,int data){
    if(root == NULL)
        return create(data);

    if(data < root->data){
        root->left = insert(root->left,data);
    }
    else if (data > root->data){
        root->right = insert(root->right,data);
    }
    else
        return root;

    root->height = 1+ max(height(root->left),height(root->right));

    int balance = getbalance(root);

    if(balance>1 && data< root->left->data){
        return rightrotate(root);
    }

    if(balance<-1 && data > root->right->data){
        return leftrotate(root);
    }
    
    if(balance>1 && data>root->left->data){
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    if(balance<-1 && data<root->right->data){
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}

void print(struct Node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        print(root->left);
        print(root->right);
    }
}


int main(int argc, char const *argv[]){
    struct Node *root = NULL;
    int size,data;
    printf("Enter Data size : ");
    scanf("%d",&size);
    printf("Eneter Your Data : ");
    scanf("%d",&data);
    for (int i = 0; i < size; i++){
        root = insert(root,data);
    }
    printf("The Result is : ");
    print(root);

    return 0;
}
