/*Target = 20
Output: 10
Explanation: From root to target the sum of node data is 25 
and from target to the children leaf nodes the sums of the node data
 are 15 and 22. So, the maximum difference will be (25-15) = 10.
https://practice.geeksforgeeks.org/problems/e841e10213ddf839d51c2909f1808632a19ae0bf/1
*/

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int targetToLeaf(Node *t){
        if(!t->left && !t->right)
            return t->data;
        int l=1e9,r=1e9;
        if(t->left)
            l=targetToLeaf(t->left);
        if(t->right)
            r=targetToLeaf(t->right);
        return min(l,r)+t->data;
    }
    //returns pair of sum from root to target and address of target node
    pair<int,Node*> func(Node* root, int target, int sum){
        if(!root)   return {-1,NULL};
        if(root->data==target)
            return {sum+root->data,root};
        if(target>root->data)
            return func(root->right, target, sum+root->data);
        return func(root->left, target, sum+root->data);
    }
    int maxDifferenceBST(Node *root,int target){
        //to check target exists ot not
        auto p = func(root,target,0);
        //if target does not exist
        if(p.first==-1)   return -1;
        //find minimum sum from target to leaf 
        int x = targetToLeaf(p.second);
        return p.first-x;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends