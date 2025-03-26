#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> & adjlist,int node, vector<bool> & visited){
        queue<int> q;
        visited[node] = true;
        q.push(node);

        while(!q.empty()){
            int currnode = q.front();
            q.pop();
            cout<<currnode<<" ";

            for(int neighbour : adjlist[currnode]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
}
void addedge(vector<vector<int>>& adjlist,int u,int v){
    adjlist[u].push_back(v);
}

int main(){
    int verticles,n,s;
    cout<<"Enter Number of Verticles : ";
    cin>>verticles;
    vector<vector<int>> adjlist(verticles);
    
    for (int i = 0; i < verticles; i++)
    {
        cout<<"Enter Node and Subnode : "<<endl;
        cin>>n;
        cin>>s;
        addedge(adjlist,n,s);
    }
    vector<bool> visited(verticles,false);
    cout<<"Result : ";
    bfs(adjlist,0,visited);
    
}
