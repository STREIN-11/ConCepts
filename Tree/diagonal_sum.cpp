#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left,* right;
};
struct Node* create(int data){
    struct Node* neww = (struct Node*)malloc(sizeof(struct Node));
    neww->data = data;
    neww->left = neww->right = NULL;
    return (neww);
}
void sumUtil(struct Node* root,int vd,map<int,int> &diagonalsum){
    if(!root)
        return;
    diagonalsum[vd] += root->data;
 
    // increase the vertical distance if left child
    sumUtil(root->left, vd + 1, diagonalsum);
 
    // vertical distance remains same for right child
    sumUtil(root->right, vd, diagonalsum); 
}

void diagonalsum(struct Node* root){
    map<int, int> diagonalsum;
     
    sumUtil(root, 0, diagonalsum);
 
    map<int, int>::iterator it;
        cout << "Diagonal sum in a binary tree is - ";
     
    for(it = diagonalsum.begin();
                it != diagonalsum.end(); ++it)
    {
        cout << it->second << " ";
    }
}
int main(){
    struct Node* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(9);
    root->left->right = create(6);
    root->right->left = create(4);
    root->right->right = create(5);
    root->right->left->right = create(7);
    root->right->left->left = create(12);
    root->left->right->left = create(11);
    root->left->left->right = create(10);
 
    diagonalsum(root);

return 0;
}
