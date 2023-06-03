/*
You are given a string str of length n. You want to choose a non-zero integer k (k<=n), such that you can perform the following operation:
Take the prefix of the string of length k and append the reverse of it to itself.
Your task is to find the lexicographically smallest string you can get.


Input:
str = "bvdfndkn"
Output:
bb
Explanation:
"bb" is the lexicographically smallest string you can get. If you choose k>1 the order of the resulting string will increase.

Input:
str = "casd"
Output:
caac
Explanation:
"caac" is the lexicographically smallest string you can get.*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
       int n=str.length();
       if(n==1) return str+str;
       string p="";
       p+=str[0];
       //cout<<p<<" ";
       for(int i=1;i<n;i++){
           if(str[i-1]>str[i]){
               p+=str[i];
           }
           else if(p.length()>1 and str[i]==str[i-1]){
               p+=str[i];
           }
           else{
               break;
           }
       }
       string g=p;
       reverse(g.begin(),g.end());
       return p+g;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends
