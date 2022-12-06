#include<bits/stdc++.h>
using namespace std;
struct Graph{
    int v;
    set<int>* adj;
};

Graph* create(int v){
    Graph* g = new Graph;
    g->v = v;
    g->adj = new set<int >[v];
    return g;
}

void addedge(Graph* graph,int src,int dest){
    graph->adj[src].insert(dest);
    graph->adj[dest].insert(src);
}

void print(Graph* graph){
    for (int i = 0; i < graph->v; ++i){
        set<int>lst = graph->adj[i];
        cout<<"At vertex : "<<i<<endl;

        for(auto itr=lst.begin();itr!=lst.end();++itr)
            cout<<*itr<<" ";
        cout<<endl;
    } 
}

void search(Graph* graph,int src,int dest){
    auto itr = graph->adj[src].find(dest);
    if(itr==graph->adj[src].end())
        cout<<"Edge from "<<src<<" to "<<dest<<" not found"<<endl;
    else
        cout<<"Edge from "<<src<<" to "<<dest<<" found"<<endl;
}

int main(){
    struct Graph* graph = create(5);
    addedge(graph,0,1);
    addedge(graph,0,4);
    addedge(graph,1,2);
    addedge(graph,1,3);
    addedge(graph,1,4);
    addedge(graph,2,3);
    addedge(graph,3,4);

    print(graph);
    search(graph,2,1);
return 0;
}