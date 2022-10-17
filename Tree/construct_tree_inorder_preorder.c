// //          A
// //        /   \
// //      /       \
// //    D B E     F C
// //          A
// //        /   \
// //      /       \
// //     B         C
// //    / \        /
// //  /     \    /
// // D       E  F
#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
	struct node* left;
	struct node* right;
};

int search(char arr[], int strt, int end, char value);
struct node* newNode(char data);

struct node* build(char in[], char pre[], int inStrt, int inEnd)
{
	static int preIndex = 0;

	if (inStrt > inEnd)
		return NULL;

	struct node* tNode = newNode(pre[preIndex++]);

	if (inStrt == inEnd)
		return tNode;
    int inIndex = search(in, inStrt, inEnd, tNode->data);

	tNode->left = build(in, pre, inStrt, inIndex - 1);
	tNode->right = build(in, pre, inIndex + 1, inEnd);

	return tNode;
}

int search(char arr[], int strt, int end, char value)
{
	int i;
	for (i = strt; i <= end; i++) {
		if (arr[i] == value)
			return i;
	}
}

struct node* newNode(char data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

void print(struct node* node)
{
	if (node == NULL)
		return;
	print(node->left);
	printf("%c ", node->data);
	print(node->right);
}

int main()
{
	char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
	char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
	int len = sizeof(in) / sizeof(in[0]);
	struct node* root = build(in, pre, 0, len - 1);

    printf("Inorder traversal of the constructed tree is \n");
	print(root);
	getchar();
}