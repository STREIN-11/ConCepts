//           12
//         /    \
//       5       7       
//     /          \ 
//    3            1
//   Leaves are at same level

//           12
//         /    \
//       5       7       
//     /          
//    3          
//    Leaves are Not at same level


//           12
//         /    
//       5             
//     /   \        
//    3     9
//   /      /
//  1      2
//  Leaves are at same level

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left,* right;
};
struct Node* create(int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->left = new->right = NULL;
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

int checksame(struct Node* root,int level,int *leaflevel){
    if(root==NULL) 
        return 1;
    if(root->left==NULL && root->right==NULL){
        if(*leaflevel==0){
            *leaflevel = level;
            return 1;
        }
        return (level == *leaflevel);
    }
    return checksame(root->left,level+1,leaflevel)&&checksame(root->right,level+1,leaflevel);

}

int check(struct Node* root){
    int level=0,leaflevel=0;
    return checksame(root,level,&leaflevel);
}

int main(int argc, char const *argv[]){
    struct Node *root = create(12);
    root->left = create(5);
    root->left->left = create(3);
    root->left->right = create(9);
    root->left->left->left = create(1);
    root->left->right->left = create(1);
    // struct Node *root = NULL;
    // root = insert(root,12);
    // root = insert(root,5);
    // root = insert(root,3);
    // root = insert(root,9);
    // root = insert(root,1);
    // root = insert(root,2);

    if (check(root))
        printf("Leaves are at same level\n");
    else
        printf("Leaves are not at same level\n");
    getchar();
    return 0;
}
