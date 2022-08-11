#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long long int nineDivisors(long long int n){
    int count=0;
       int upper_limit=sqrt(n);
       int prime[upper_limit+1];
       for(int i=1;i<=upper_limit;i++)
           prime[i]=i;
       for(int i=2;i*i<=upper_limit;i++){
           if(prime[i]==i){
               for(int j=i*i;j<=upper_limit;j=j+i)
                   if(prime[j]==j)
                       prime[j]=i;
           }
       }
       for(int i=2;i<=upper_limit;i++){
           int x=prime[i];
           int y=prime[i/prime[i]];
           if(x*y==i and y!=1 and x!=y){
               count=count+1;
           }
           else if(prime[i]==i){
               if(pow(i,8)<=n){
                   count=count+1;
               }
           }
       }
       return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.nineDivisors(N) << endl;
    }
    return 0; 
}