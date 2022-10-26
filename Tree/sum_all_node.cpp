#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left,* right;
};
Node* create(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int add(Node* root){
    if(root==0)
        return 0;
    return (root->data + add(root->left) + add(root->right));  
}

int main(){
    Node* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);
    root->right->left = create(6);
    root->right->right = create(7);
    root->right->left->right = create(8);
    int sum = add(root);
    cout<<"The Sum is : " <<sum<<endl;
return 0;
}