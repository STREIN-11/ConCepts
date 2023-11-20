/*
Given two arrays that represent Preorder traversals of a Full binary tree preOrder[] and its mirror tree preOrderMirror[], 
your task is to complete the function constructBinaryTree(), that constructs the full binary tree using these two Preorder traversals.

Note: It is not possible to construct a general binary tree using these two traversal. But it is possible to create a full binary 
tree using the above traversals without any ambiguity.
Input :
preOrder[] = {0,1,2}
preOrderMirror[] = {0,2,1} 

Output :
                0
              /   \
             1     2
Explanation :
Tree in the output and it's mirror tree matches the preOrder and preOrderMirror.

Input :  
preOrder[] = {1,2,4,5,3,6,7}
preOrderMirror[] = {1,3,7,6,2,5,4}

Output :          
                 1
               /    \
              2      3
            /   \   /  \
           4     5 6    7
Explanation :
Tree in the output and it's mirror tree matches the preOrder and preOrderMirror.*/

//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
    Node* constructBinaryTree(int pre[], int preMirror[], int size, int l=0, int a=0)
    {
        Node*n = new Node(pre[l++]);
        if(size == 1)
            return n;
        a++;
        n->left = constructBinaryTree(pre, preMirror, size/2,l,a+size/2 );
        n->right = constructBinaryTree(pre, preMirror, size/2,l+size/2,a);
        return n;
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
