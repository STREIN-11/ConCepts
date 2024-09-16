/*
You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:
Input:
grid[][] = {{0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}}

Output:
3
Explanation:
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0
The highlighted cells represents the land cells.

Example 2:
Input:
grid[][] = {{0, 0, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {0, 1, 1, 0}}
Output:
4
Explanation:
0 0 0 1
0 1 1 0
0 1 1 0
0 0 0 1
0 1 1 0
The highlighted cells represents the land cells.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(int i,int j,vector<vector<int>> &visit,vector<vector<int>> &grid){
        visit[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        int row[] = {1,0,-1,0};
        int col[] = {0,1,0,-1};
        
        for(int k=0;k<4;k++){
            int nr = i+row[k];
            int nc = j+col[k];
            
            if(nr<0||nr>=n||nc<0||nc>=m) continue;
            
            if(grid[nr][nc]==1 && !visit[nr][nc]){
                visit[nr][nc] = 1;
                dfs(nr,nc,visit,grid);
            }
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visit(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0||j==m-1||i==n-1){
                    if(grid[i][j]==1 && !visit[i][j]){
                        dfs(i,j,visit,grid);
                    }
                }
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visit[i][j])
                    count++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
