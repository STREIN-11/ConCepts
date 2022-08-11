#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int n,m;
    
    void dfs(int i, int j, vector<vector<char>>& grid){
        
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='O'){
            return;
        }
        grid[i][j]='O';
        
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        dfs(i-1,j,grid);
    }
    
    int xShape(vector<vector<char>>& grid) 
    {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0; j<m;j++){
                if(grid[i][j]=='X'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
      
      return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}