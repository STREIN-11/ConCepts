#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left,*right;
};



struct node* newnode(int n){
    struct node* temp = new struct node;
    temp->data = n;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node,int data){
    if(node==NULL)
        return newnode(data);
    if(data<node->data)
        node->left = insert(node->left,data);
    else if(data>node->data)
        node->right = insert(node->right,data);
    return node;
}

struct node* search(struct node* root,int k){
    if(root==NULL || root->data==k)
        return root;

    if(root->data<k)
        return search(root->right,k);

    return search(root->left, k);
}

int main(){
    struct node *root = NULL;
    int N;
    cout<<"Enter Length : ";
    cin >> N;
    for (int i = 0; i < N; i++) {
        int d;
        cout<<"Enter data : ";
        cin >> d;
        root = insert(root, d);
    }
    int k;
    cout<<"Enter The Number want to find : ";
    cin>>k;

    if(search(root,k)==NULL)
        cout<<"Not Found";
    else
        cout<<"Found";
}
