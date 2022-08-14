/*Tree = 
           1
        /    \
       2       3
     /  \     /  \
    4    5   6    7                        
   /        / \                        
  8        9   10   
first node = 5
second node = 10
Output: 4
Explanation: 
Turns will be at 2, 1, 3, 6.
*/
//{ Driver Code Starts
//Initial template for C++

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

    // Creating vector of strings from input string after spliting by space
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
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/
class Solution{
    private:
    int z1 = 0, z2 = 0;
    Node* LCA(Node* root, int first, int second){
        if(root == NULL || root->data == first || root->data == second){
            return root;
        }
        Node* left = LCA(root->left, first, second);
        Node* right = LCA(root->right, first, second);
        
        if(left == NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }
        else    return root;
    }
    
    void turns(Node* lca, int first, int second, int dir, int turn){
        if(!lca)   return;
        if(lca->data == first) z1 = turn;
        if(lca->data == second)    z2 = turn;
        // left = 1, right = 0;
        if(dir == -1){
            turns(lca->left, first, second, 1, turn);
            turns(lca->right, first, second, 0, turn);
        }
        if(dir == 0){
            turns(lca->left, first, second, 1, turn+1);
            turns(lca->right, first, second, 0, turn);
        }
        
        if(dir == 1){
            turns(lca->left, first, second, 1, turn);
            turns(lca->right, first, second, 0, turn+1);
        }
    }
    
  public:
    // function should return the number of turns required to go from first node to second node 
    int NumberOFTurns(struct Node* root, int first, int second)
    {
        Node* LCA_ = LCA(root, first, second);
        int ans = -1;
        turns(LCA_, first, second, -1, 0);
        if(LCA_->data == first || LCA_->data == second){
                return abs(z1-z2);
        }
        return z1 + z2 + 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}

// } Driver Code Ends