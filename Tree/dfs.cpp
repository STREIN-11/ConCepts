#include <bits/stdc++.h>
using namespace std;
class graph{
public:
    map<int,bool>visited;
    map<int,list<int>> adj;
    void addedge(int v,int w);
    void dfs(int v);
};

void graph::addedge(int v,int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void graph::dfs(int v){
    visited[v] = true;
    cout<<v<<" ";
    list<int>::iterator i;
    for(i = adj[v].begin(); i!=adj[v].end(); ++i){
        if(!visited[*i])
            dfs(*i);
    }
}

int main(){
    graph g;
    int size,data1,data2,v;
    cout<<"Enter Size: ";
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter Node & Edges : ";
        cin>>data1;
        cin>>data2;
        g.addedge(data1,data2);
    }
    cout<<"Enter Starting Vertex : ";
    cin>>v;
    g.dfs(v);
    

}