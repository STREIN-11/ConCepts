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

int leftsum(struct Node *root)
{
    int res = 0;
    if (root != NULL)
    {
        if (check(root->left))
            res += root->left->data;
        else
            res += leftsum(root->left);
        res += leftsum(root->right);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    struct Node *root = create(20);
    root->left = create(9);
    root->right = create(49);
    root->right->left = create(23);
    root->right->right = create(52);
    root->right->right->left = create(50);
    root->left->left = create(5);
    root->left->right = create(12);
    root->left->right->right = create(12);
    printf("Sum of left leaves is :%d",leftsum(root));
    return 0;
}
