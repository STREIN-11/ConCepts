#include <bits/stdc++.h>
using namespace std;
#define MAX_VERTICES 100
struct Node{
    int data;
    struct Node* next;
};
struct Node* createnode(int data){
    struct Node* neww = (struct Node*)malloc(sizeof(struct Node));
    neww->data = data;
    neww->next = NULL;
    return neww;
}
void addedge(struct Node* arr[],int u,int v){
    struct Node* newnode = createnode(v);
    newnode->next = arr[u];
    arr[u] = newnode;

    newnode = createnode(u);
    newnode->next = arr[v];
    arr[v] = newnode;
}
void bfs(struct Node* arr[],int ver,int sour,int visited[]){
    int queue[MAX_VERTICES];
    int front = 0,rear = 0;

    visited[sour] = 1;
    queue[rear++] = sour;

    while(front != rear){
        int curr = queue[front++];
        cout<<curr;

        struct Node* temp = arr[curr];
        while (temp!= NULL){
            int nei = temp->data;
            if(!visited[nei]){
                visited[nei] = 1;
                queue[rear++] = nei;
            }
            temp = temp->next;
        }
        
    }
}

int main(){
    int v,n,l;
    cout<<"Enter Number of vertices : ";
    cin>>v;
    struct Node* arr[v];
    for (int i = 0; i < v; i++)
        arr[i] = NULL;

    for (int i = 0; i < v; i++){
        cout<<"Add Node and Leaf node : "<<endl;
        cin>>n;
        cin>>l;
        addedge(arr,n,l);
    }
    int visited[v];
    for(int i = 0; i<v; i++)
        visited[i] = 0;
    cout<<"BFS is : ";
    bfs(arr,v,0,visited);
}