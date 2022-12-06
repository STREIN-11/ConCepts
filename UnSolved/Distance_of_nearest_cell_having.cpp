/*Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 
are the row number and column number of the nearest cell having value 1.
Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.

Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
Output: {{0,1,0},{0,0,1},{0,1,2}}
Explanation: The grid is-
1 0 1
1 1 0
1 0 0
0's at (0,1), (1,2), (2,1) and (2,2) are at a 
distance of 1, 1, 1 and 2 from 1's at (0,0),
(0,2), (2,0) and (1,1) respectively.


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	 bool isCellValid(vector<vector<int>> &grid, int i, int j){
       if(i>=0 and i<grid.size() and j>=0 and j<grid[0].size() and grid[i][j] == INT_MAX)
        return true;
       return false;
    }
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    queue<pair<int,int>>q;
	   for(int i = 0;i<grid.size();i++){
	       for(int j =  0; j<grid[0].size();j++){
	           if(grid[i][j] == 1){
	               q.push({i,j});
	               grid[i][j] = 0;
	           }
	           else{
	           grid[i][j] = INT_MAX;
	         }
	       }
	   }
	   
	   while(!q.empty()){
	       int x = q.front().first;
	       int y = q.front().second;
	       q.pop();
	       int dx[] = {1,-1,0,0};
	       int dy[] = {0,0,-1,1};
	       
	       for(int k = 0;k<4;k++){
	           int nx = x+dx[k];
	           int ny = y+dy[k];
	           
	           if(isCellValid(grid,nx,ny)){
	               q.push({nx,ny});
	               grid[nx][ny] = grid[x][y]+1;
	           }
	       }
	   }
	   return grid;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends