/*
Scrambled string: Given string str, we can represent it as a binary tree by partitioning it into two non-empty substrings recursively.
Below is one possible representation of str = coder:
To scramble the string, we may choose any non-leaf node and swap its two children. 
Suppose, we choose the node co and swap its two children, it produces a scrambled string ocder.
Similarly, if we continue to swap the children of nodes der and er, it produces a scrambled string ocred.
Note: Scrambled string is not the same as an Anagram.
Print "Yes" if S2 is a scrambled form of S1 otherwise print "No".

Example 1:












Input: S1="coder", S2="ocder"
Output: Yes
Explanation: ocder is a scrambled 
form of coder.

    ocder
   /    \
  oc    der
 / \    
o   c  

As "ocder" can represent it 
as a binary tree by partitioning 
it into two non-empty substrings.
We just have to swap 'o' and 'c' 
to get "coder".

Input: S1="abcde", S2="caebd" 
Output: No
Explanation: caebd is not a 
scrambled form of abcde.*/

//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++


class Solution{
    public:
    map<string,int>m;
    bool fun(string s1,string s2){
        if(s1==s2)return true;
        int n=s1.size();
        if(n==0)return false;
        string temp=s1+"-"+s2;
        
        if(m.find(temp)!=m.end())return m[temp];
        bool res=false;
        
        for(int i=1;i<n;i++){
            res|=(fun(s1.substr(0,i),s2.substr(0,i))&&fun(s1.substr(i),s2.substr(i)));
            res|=(fun(s1.substr(0,i),s2.substr(n-i))&&fun(s1.substr(i),s2.substr(0,n-i)));
        }
        return m[temp]=res;
    }
    bool isScramble(string s1, string s2){
        int n=s1.size();
        return fun(s1,s2);
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
