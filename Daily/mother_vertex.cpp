/*
Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.

https://practice.geeksforgeeks.org/problems/mother-vertex/1
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	void dfs(vector<int>adj[], int i, vector<bool> &visted )
    {
        visted[i]=true;
        for(auto x: adj[i])
        {
            if(visted[x])
            continue;
            dfs(adj, x,visted);
        }
    }
    //Function to find a Mother Vertex in the Graph.
int findMotherVertex(int V, vector<int>adj[])
{
    // Code here
        vector<bool> visted(V, false);
        int mv=-1;
    for(int i=0; i<V; i++)
    {
        if(!visted[i])
        {
            dfs(adj, i, visted);
            mv=i;
        }
    }
      fill(visted.begin(), visted.end(), false);
          dfs(adj, mv, visted);
 
            for (bool v : visted) 
            {
                if (!v) {
                    return -1;
                }
            }
 
    return mv;
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
