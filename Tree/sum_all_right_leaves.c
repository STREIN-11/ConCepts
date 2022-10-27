// Input : 
//          1
//         /  \
//        2    3
//      /  \     \
//     4    5     8 
//      \        /  \
//       2       6   7

// Output :
// sum = 2 + 5 + 7 = 14

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *create(int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->left = new->right = NULL;
    return (new);
}

int check(struct Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return 0;
}

int rightsum(struct Node *root)
{
    int res = 0;
    if (root != NULL)
    {
        if (check(root->right))
            res += root->right->data;
        else
            res += rightsum(root->right);
        res += rightsum(root->left);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    struct Node *root = create(1);
    root->left = create(2);
    root->left->left = create(4);
    root->left->right = create(5);
    root->left->left->right = create(2);
    root->right = create(3);
    root->right->right = create(8);
    root->right->right->left = create(6);
    root->right->right->right = create(7);
    printf("Sum of right leaves is :%d",rightsum(root));
    
    return 0;
}
