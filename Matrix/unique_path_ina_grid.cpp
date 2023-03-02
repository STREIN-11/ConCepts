/*
You are given a matrix grid of n x  m size consisting of values 0 and 1. 
A value of 1 means that you can enter that cell and 0 implies that entry 
to that cell is not allowed.

You start at the upper-left corner of the grid (1, 1) and you have to 
reach the bottom-right corner (n, m) such that you can only move in the
 right or down direction from every cell.

Your task is to calculate the total number of ways of reaching the
 target modulo (109+7).
Note: The first (1, 1) and last cell (n, m) of the grid can also be 0

Input:
n = 3, m = 3
grid[][] = {{1, 1, 1};
            {1, 0, 1};
            {1, 1, 1}}
Output:
2
Explanation:
1 1 1
1 0 1
1 1 1
This is one possible path.
1 1 1
1 0 1
1 1 1
This is another possible path.

Example 2:

Input:
n = 1, m = 3
grid = {{1, 0, 1}}
Output :
0
Explanation:
There is no possible path to reach the end.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        if (grid[0][0] == 0 || grid[n - 1][m - 1] == 0)
        {
            return 0;
        }
        std::vector<std::vector<long>> dp(n,std::vector<long>(m,-1));
        int mod = 1000000000 + 7;
        return (int)(Solution::solve(0, 0, n, m, grid, dp) % mod);
    }
    static long solve(int i,int j,int n,int m,std::vector<std::vector<int>> &grid,std::vector<std::vector<long>> &dp)
    {
        if (i == n - 1 && j == m - 1)
        {
            return 1;
        }
        if (i >= n || j >= m)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int count = 0;
        int mod = 1000000000 + 7;
        if (i + 1 < n && grid[i + 1][j] == 1)
        {
            count += (Solution::solve(i + 1, j, n, m, grid, dp) % mod);
        }
        if (j + 1 < m && grid[i][j + 1] == 1)
        {
            count += (Solution::solve(i, j + 1, n, m, grid, dp) % mod);
        }
        return dp[i][j] = count % mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends