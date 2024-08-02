#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left,*right;
};
struct Node* newnode(int add){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = add;
    temp->left = temp->right = NULL;
}
struct Node* insert(struct Node* node,int data){
    if(node==NULL)
        return newnode(data);
    if(node->data == data)
        return node;
    if(node->data<data){
        node->right =  insert(node->right,data);
    }
    else{
        node->left = insert(node->left,data);
    }
    return node;
}
void insert_hassh(Node* root,unordered_set<int> &s){
    if(!root)
        return;
    insert_hassh(root->left,s);
    s.insert(root->data);
    insert_hassh(root->right,s);
}

bool check(Node* root,Node* roo){
    if(!root && !roo)
        return true;
    if((root && !roo) || (!root && roo))
        return false;
    
    unordered_set<int> s1,s2;
    insert_hassh(root,s1);
    insert_hassh(roo,s2);
    return (s1==s2);

}

int main(){
    struct Node* root = NULL;
    struct Node* roo = NULL;
    int n,m,data1,data2;
    cout<<"Enter First size : ";
    cin>>n;
    cout<<"Enter First Data : ";
    for (int i = 0; i < n; i++)
    {
        cin>>data1;
        root = insert(root,data1);
    }

    cout<<"Enter Second size : ";
    cin>>m;
    cout<<"Enter Second Data : ";
    for (int i = 0; i < m; i++)
    {
        cin>>data2;
        roo = insert(roo,data2);
    }
    if(n!=m){
        cout<<"NO";
    }
    else if(check(root,roo)){
        cout<<"YES";
    }
    else
        cout<<"NO";

}