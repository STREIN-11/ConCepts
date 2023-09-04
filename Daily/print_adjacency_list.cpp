/*
Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph. 0-based indexing is followed everywhere.

Example 1:

Input:
V = 5, E = 7
edges = {(0,1),(0,4),(4,1),(4,3),(1,3),(1,2),(3,2)}
Output: 
{{1,4}, 
 {0,2,3,4}, 
 {1,3},
 {1,2,4},
 {0,1,3}}
Explanation:
Node 0 is connected to 1 and 4.
Node 1 is connected to 0,2,3 and 4.
Node 2 is connected to 1 and 3.
Node 3 is connected to 1,2 and 4.
Node 4 is connected to 0,1 and 3.

Example 2:

Input:
V = 4, E = 3
edges = {(0,3),(0,2),(2,1)}
Output: 
{{2,3} 
 {2}, 
 {0,1} 
 {0}}
Explanation:
Node 0 is connected to 2 and 3.
Node 1 is only connected to 2.
Node 2 is connected to 0 and 1.
Node 3 is only connected to 0.*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<vector<int>>al(V);
        for(auto x : edges)
        {
            al[x.first].push_back(x.second);
            al[x.second].push_back(x.first);
        }
        
        return al;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int,int>>edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u,v});
        }
        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        for(int i=0;i<V;i++)
        {
            sort(adj[i].begin(),adj[i].end());
            for(auto it:adj[i])
                cout<<it<<" ";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends