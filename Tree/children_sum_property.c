//      10
//    /   \
//   8     2
//  /  \    \
// 3    5    2

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

int sum(struct Node* node){
    int left = 0,right = 0;
    if (node == NULL|| (node->left == NULL && node->right == NULL))
        return 1;
    else{
        if (node->left != NULL)
            left = node->left->data;
        if(node->right != NULL)
            right = node->right->data;
        if ((node->data == left + right)&& sum(node->left) && sum(node->right))
            return 1;
        else
            return 0;   
    }
}

struct Node* create(int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
}

struct Node* insert(struct Node* root,int data){
    if (root==NULL){
        return create(data);
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

int main(int argc, char const *argv[]){
    // struct Node *root = NULL;
    // root = insert(root, 10);
    // root = insert(root, 8);
    // root = insert(root, 2);
    // root = insert(root, 3);
    // root = insert(root, 5);
    // root = insert(root, 2);

    struct Node* root = create(10);
    root->left = create(8);
    root->right = create(2);
    root->left->left = create(3);
    root->left->right = create(5);
    root->right->right = create(2);

    if (sum(root)){
        printf("YES");
    }
    else{
        printf("NO");
    }
    getchar();
    return 0;
}
