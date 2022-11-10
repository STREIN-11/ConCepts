#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* create(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int maxvalue(struct Node* root){
    if(root == NULL)
        return 0;
    int leftmax = maxvalue(root->left);
    int rightmax = maxvalue(root->right);

    int val = 0;
    if(leftmax > rightmax){
        val = leftmax;
    }
    else{
        val = rightmax;
    }
    if(val>root->data){
        val = root->data;
    }
    return val;
}

int minvalue(struct Node* root){
    if(root == NULL)
        return 0;
    int leftmin = minvalue(root->left);
    int rightmin = minvalue(root->right);
    int val = 0;
    if(leftmin<rightmin){
        val = leftmin;
    }
    else{
        val = rightmin;
    }
    if(val<root->data){
        val = root->data;
    }
    return val;
}

int check(struct Node* root){
    if(root == NULL)
        return 1;
    if(root->left != NULL && maxvalue(root->left)>root->data)
        return 0;
    if(root->right!=NULL && minvalue(root->right)<root->data)
        return 0;
    if(!check(root->left) || !check(root->right))
        return 0;
    return 1;
}

int main(int argc, char const *argv[]){
    struct Node* root = create(4);
    root->left = create(2);
    root->right = create(5);
    root->left->left = create(1);
    root->left->right = create(3);
 
    // Function call
    if (check(root))
        printf("Is BST");
    else
        printf("Not a BST");
 
    getchar();
    return 0;
}
