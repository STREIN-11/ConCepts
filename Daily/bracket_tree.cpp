/*
Input: "1(2)(3)" 
Output: 2 1 3
Explanation:
           1
          / \
         2   3
Explanation: first pair of parenthesis contains 
left subtree and second one contains the right 
subtree. Inorder of above tree is "2 1 3".*/
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    Node* helper(string &str, int st, int end) {
        if(st > end) return NULL;
        int num = 0;
        int i = st;
        while(i <= end && str[i] != '(') {
            num = num * 10 + (str[i] - '0');
            i++;
        }
        Node* curr = new Node(num);
        Node* left = NULL, *right = NULL;
        
        int cnt = 1;
        i++;
        int leftSt = i;
        while(i <= end && cnt > 0) {
            if(str[i] == '(') cnt++;
            else if (str[i] == ')') cnt--;
            i++;
        }
        int leftEnd = i-2;
        left = helper(str, leftSt, leftEnd);
        cnt = 1;
        i++;
        int rightSt = i;
        while(i <= end && cnt > 0) {
            if(str[i] == '(') cnt++;
            else if (str[i] == ')') cnt--;
            i++;
        }
        int rightEnd = i-2;
        right = helper(str, rightSt, rightEnd);
        
        curr->left = left;
        curr->right = right;
        return curr;
    }
    
    Node *treeFromString(string str){
        // code here
        int n = str.size();
        return helper(str, 0, n-1);
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends