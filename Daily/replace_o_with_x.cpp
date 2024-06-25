/*
Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' with 'X' that are surrounded by 'X'.
A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.





Example 1:
Input: 
n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix. 

Example 2:
Input: 
n = 5, m = 4
mat = {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix.*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        queue<pair<int,int>>q;
       for(int i=0; i<n; i++){
           if(mat[i][0]=='O'){
               mat[i][0]='1';
               q.push({i,0});
           }
           if(mat[i][m-1]=='O'){
               mat[i][m-1]='1';
               q.push({i,m-1});
               
           }
       }
       for(int i=1; i<m-1; i++){
           if(mat[0][i]=='O'){
               mat[0][i]='1';
               q.push({0,i});
               
           }
           if(mat[n-1][i]=='O'){
               mat[n-1][i]='1';
               q.push({n-1,i});
               
           }
               
       }
       int disr[4]={-1,0,1,0};
       int disc[4]={0,1,0,-1};
    
      while(!q.empty()){
          auto node = q.front();q.pop();
          int row = node.first;
          int col = node.second;
          mat[row][col]='1';
          for(int i=0; i<4; i++){
              int nrow = row + disr[i];
              int ncol = col + disc[i];
               
              if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]=='O'){
                  q.push({nrow,ncol});
              }
          }
      }
       
      for(int i =0; i<n; i++){
          for(int j =0; j<m; j++){
              if(mat[i][j]=='O') mat[i][j]='X';
              if(mat[i][j]=='1')mat[i][j]='O';
          }
      }
       
       return mat;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
