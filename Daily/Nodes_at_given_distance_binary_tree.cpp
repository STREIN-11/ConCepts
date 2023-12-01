/*
Given a binary tree, a target node in the binary tree, and an integer value k, 
find all the nodes that are at distance k from the given target node. No parent 
pointers are available.


Note:
    You have to return the list in sorted order.
    The tree will not contain duplicate values.

Example 1:
Input:      
          20
        /    \
      8       22 
    /   \
   4    12 
       /   \
      10    14
Target Node = 8
K = 2
Output: 10 14 22
Explanation: The three nodes at distance 2
from node 8 are 10, 14, 22.

Example 2:
Input:      
         20
       /    \
      7      24
    /   \
   4     3
        /  
       1    
Target Node = 7
K = 2
Output: 1 24
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));
        
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
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Graph {
    public:
    int N;
    vector<int> nodes, parent;
    map<int,int> coordinates;
    map<int,int> decompress;
    vector<int> depth;
    vector<vector<int>> jump;
    public:
    void coordinateCompress() {
        sort(nodes.begin(), nodes.end());
        int T = 0;
        for(auto &it : nodes) {
            coordinates[it] = T;
            decompress[T++] = it;
        }
        N = T;
        parent = vector<int> (N, -1);
        depth = vector<int> (N, 0);
        jump = vector<vector<int>> (N, vector<int> (20));
    }
    void dfs2(Node *root, Node *par = NULL, int T = 0) {
        if(root == NULL) return;
        int u = -1;
        if(par != NULL) u = coordinates[par->data];
        int v = coordinates[root->data];
        depth[v] = T;
        parent[v] = u;
        dfs2(root->left, root, T+1);
        dfs2(root->right, root, T+1);
    }
    void dfs(Node *root) {
        if(root == NULL) return ;
        nodes.push_back(root->data);
        dfs(root->left);
        dfs(root->right);
    }
    void binaryLift() {
        for(int i = 0; i < N; i++) {
            jump[i][0] = parent[i];
        }
        for(int l = 1; l <= 20; l++) {
            for(int i = 0; i < N; i++) {
                if(jump[i][l-1] == -1) continue;
                jump[i][l] = jump[jump[i][l-1]][l-1];
            }
        }
    }
    int findLca(int a, int b) {
        if(depth[a] > depth[b]) swap(a, b);
        int depthDiff = depth[b] - depth[a];
        for(int i = 0; i <= 20; i++) {
            if(depthDiff & (1 << i)) {
                b = jump[b][i];   
            }
        }
        if(a == b) return a;
        for(int l = 20; l >= 0; l--) {
            if(jump[a][l] != jump[b][l]) {
                a = jump[a][l];
                b = jump[b][l];
            }
        }
        return jump[a][0];
    }
    vector<int> answer(int target, int k) {
        vector<int> ans;
        for(int i = 0; i < N; i++) {
            int lca = findLca(target, i);
            int dis = depth[target] + depth[i] - 2 * depth[lca];
            if(dis == k) ans.push_back(decompress[i]);
        }
        return ans;
    }
};

class Solution {
private:

public:
    vector <int> KDistanceNodes(Node* root, int target , int k)    {
        Graph g;   
        g.dfs(root);
        g.coordinateCompress();
        g.dfs2(root);
        g.binaryLift();
        vector<int> ans = g.answer(g.coordinates[target], k);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
