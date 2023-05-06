/*
You are given a root node of a binary Tree and each node of the binary tree is assigned a value and you are also given an integer 
k and you have to return the count of Good subtrees of this binary Tree . Good subtree is a subtree such that the number of 
distinct values in this subtree is less than or equal to k.
Note: Subtree of a node consists of that node and all nodes of the subtrees of left and right child  of that node  if they exist .

https://practice.geeksforgeeks.org/problems/df12afc57250e7f6fc101aa9c272343184fe9859/1*/







#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int ans = 0;
    vector<int> rec(Node *root, int k) {
        if(!root) return vector<int>(30);
        vector<int> lft = rec(root->left, k);
        vector<int> rght = rec(root->right, k);
        vector<int> now(30);
        ++now[root->data];
        for(int i=1; i<30; i++) {
            now[i] += lft[i];
            now[i] += rght[i];
        }
        int cnt = 0;
        for(int i=1; i<30; i++) {
            if(now[i]) ++cnt;
        }
        ans += (cnt<=k);
        return now;
    }
    int goodSubtrees(Node *root,int k){
        ans = 0;
        rec(root, k);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        if(i==0){
            string s;
            getline(cin,s);
        }
        string str;
        getline(cin,str);
        int k;
        cin>>k;
        string newline;
        getline(cin,newline);
        Node* root = buildTree(str);
        Solution ob;
        cout<<ob.goodSubtrees(root,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
