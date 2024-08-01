#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newnode(int data){
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = data;
    root->left = root->right = NULL;
}
struct Node* insert(struct Node* node,int data){
    if(node==NULL){
        return newnode(data);
    }
    if(node->data==data){
        return node;
    }
    if(node->data<data){
        node->right = insert(node->right,data);
    }
    else
        node->left = insert(node->left,data);
    return node;
}

struct Node* search(struct Node* root,int data){
    if(root==NULL || root->data == data)
        return root;
    if(root->data<data)
        return search(root->right,data);
    return search(root->left,data);
}

void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" - ";
        inorder(root->right);
    }
}

int main(){
    int n;
    struct Node* root = newnode(50);
    root = insert(root,30);
    root = insert(root,40);
    root = insert(root,60);
    root = insert(root,70);
    root = insert(root,10);
    root = insert(root,20);
    inorder(root);
    cout<<"\nEnter Data Want to search : ";
    cin>>n;
    if(search(root, n) != NULL){
        cout<<"Found";
    }
    else 
        cout<<"Not Found";

}