/*
You are given a tree rooted at node 1. The tree is given in form 
of an array P where Pi denotes the parent of node i, Also P1 = -1, as 1 
is the root node. Every node i has a value Ai associated with it.
 At first, you have to choose any node to start with, after that 
 from a node you can go to any of its child nodes. You've to keep
  moving to a child node until you reach a leaf node. Every time 
  you get to a new node, you write its value. Let us assume that 
  the integer sequence in your path is B.
Let us define a function f over B, which is defined as follows:
f(B) = B1 - B2 + B3 - B4 + B5.... + (-1)(k-1)Bk.
You have to find the maximum possible value of f(B).
















Input:
N = 3,
A = { 1, 2, 3}
P = {-1, 1, 1}
Output:
3
Explanation:
The resulting tree is:
        1(1)
      /     \
     2(2)   3(3)
If we choose our starting node as 3, then the
resulting sequence will be B = { 3 },
which will give the maximum possible value.

Input:
N = 3,
A = { 3, 1, 2}
P = {-1, 1, 2}
Output:
4
Explanation:
The resulting tree is:
  1(3)
  |
  2(1)
  |
  3(2)
If we choose our starting node as 1, then the
resulting sequence will be B = { 3 , 1 , 2 }.
The value which we'll get is, 3-1+2 = 4, which
is the maximum possible value.*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        // code here
        unordered_map<int,int> mp;
        for(int i=1;i<N;i++){
            mp[P[i]]=1;
        }
        set<int> leaf;
        for(int i=1;i<=N;i++){
            if(mp.find(i)==mp.end()){
                leaf.insert(i);
            }
        }
        long long max=INT_MIN;
        for(int a:leaf){
            int val=0;
            do{
                //cout<<a<<" ";
                val=A[a-1]-val;
                max=max<val?val:max;
                //cout<<a<<" "<<val<<endl;
                a=P[a-1];
            }while(a!=-1);
            //cout<<endl;
        }
        
        return max;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
