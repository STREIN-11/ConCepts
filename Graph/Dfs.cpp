#include<bits/stdc++.h>
using namespace std;
class Graph{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    void addedges(int v,int w);
    void dfs(int v);
};
void Graph::addedges(int v,int w){
    adj[v].push_back(w);
}

void Graph::dfs(int v){
    visited[v] = true;
    cout<<v<<" ";
    list<int>::iterator i;
    for(i = adj[v].begin(); i!=adj[v].end(); ++i)
        if(!visited[*i])
            dfs(*i);
}

int main(){
    Graph g;
    g.addedges(0,1);
    g.addedges(0,2);
    g.addedges(1,2);
    g.addedges(2,0);
    g.addedges(2,3);
    g.addedges(3,3);
    cout<<"Result : ";
    g.dfs(1);

return 0;
}