/*
There is a rectangular path for a Train to travel consisting of n rows and m columns. The train will start from one of the grid's
cells and it will be given a command in the form of string s consisting of characters L, R, D, U. Find if it is possible to travel the train 
inside the grid only.
Note:
If the train is at position (i,j)
on taking 'L' it goes to (i,j-1),
on taking 'R' it goes to (i,j+1),
on taking 'D' it goes to (i-1,j),
on taking 'U' it goes to (i+1,j).







Input: 
n = 1, m = 1
s = "R"
Output: 0
Explaination: There is only one cell(1,1). So train can only start from (1,1). On taking right(R) train moves to (1,2), which is out of grid.
Therefore there is no cell from where train can start and remain inside the grid after tracing the route. 

Input: 
n = 2, m = 3
s = "LLRU"
Output: 1
Explaination: One possible cell is (1,3)
(1,3) --> (1,2) --> (1,1) --> (1,2) --> (2,2). Thus there is a cell from where if train starts*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        int col=0;
        int row=0;
        int lm=0;
        int rm=0;
        int um=0;
        int dm=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='L')col--;
            if(s[i]=='R')col++;
            if(s[i]=='U')row++;
            if(s[i]=='D')row--;
            
            lm=min(lm,col);
            rm=max(rm,col);
            dm=min(dm,row);
            um=max(um,row);
        }
        
        if(rm-lm<m && um-dm<n)return 1;
        return 0;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
