#include <bits/stdc++.h>
using namespace std;

class graph{
    int v;
    list<int>* adj;
    bool iscycle(int v,bool visited[], int parent);
public:
    graph(int v);
    void addedge(int v,int w);
    bool iscyc();
};

graph::graph(int v){
    this->v = v;
    adj = new list<int>[v];
}

void graph::addedge(int v,int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool graph::iscycle(int v,bool visited[],int parent){
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i!= adj[v].end(); ++i)
    {
        if(!visited[*i]){
            if(iscycle(*i,visited,v))
                return true;
        }
        else if (*i != parent)
            return true;
        
    }
    return false;
}

bool graph::iscyc(){
    bool* visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int j = 0; j < v; j++)
    {
        if(!visited[j])
            if(iscycle(j,visited,-1))
                return true;
    }
    return false;
    
}

int main(){
    int size,data1,data2;
    cout<<"Enter Size : ";
    cin>>size;
    graph g(size);
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter Node & Edges : "<<endl;
        cin>>data1;
        cin>>data2;
        g.addedge(data1,data2);
    }
    g.iscyc()?cout<<"It's Cyclic":cout<<"Graph is not cyclic";

}