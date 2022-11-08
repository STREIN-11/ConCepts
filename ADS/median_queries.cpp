//Example :  https://media.geeksforgeeks.org/wp-content/cdn-uploads/efficiently-designed_1.png
#include<bits/stdc++.h>
using namespace std;
#define maxn 3000005
#define max_elem 1000000

int tree[maxn];
void update(int node,int a,int b,int x,int diff){
   if(a == b && a==x){
       tree[node] += diff;
   }
   if(x>=a && x<=b){
       update(node*2,a,(a+b)/2,x,diff);
       update(node*2+1,(a+b)/2+1,b,x,diff);
       tree[node] = tree[node*2] + tree[node*2+1];
   }
}

int kth(int node,int a,int b,int k){
    
}


int main(){

return 0;
}