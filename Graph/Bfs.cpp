#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    vector<list<int>> adj;
  
public:
    Graph(int V);
    void addedge(int v,int w);
    void bfs(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj.resize(V);
}

void Graph::addedge(int v,int w){
    adj[v].push_back(w);
}

void Graph::bfs(int s){
    vector<bool> visited;
    visited.resize(V,false);

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    while(!queue.empty()){
        s = queue.front();
        cout<<s<<" ";
        queue.pop_front();

        for (auto adjecent: adj[s]){
            if (!visited[adjecent]){
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
}

int main(){
    Graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
    printf("Result : ");
    g.bfs(2);

return 0;
}
