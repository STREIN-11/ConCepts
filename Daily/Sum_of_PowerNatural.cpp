/*
Given two numbers n and x, find out the total number of ways n can be expressed as the sum of the Xth power of unique natural numbers. 
As the total number of ways can be very large, so return the number of ways modulo 109 + 7. 

Input: 
n = 10, x = 2
Output: 
1 
Explanation: 
10 = 12 + 32, Hence total 1 possibility. 

Input: 
n = 100, x = 2
Output: 
3
Explanation: 
100 = 102 
62 + 82 and 12 + 32 + 42 + 52 + 72 
Hence total 3 possibilities. */

//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int numOfWays(int n, int x)
    {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(n, x, 1, dp);
    }
    
    long long solve(int n, int x, int a, vector<vector<int>>& dp) {
        if(n == 0) return 1;
        int value = 1;
        for(int i = 0; i < x; i++) value *= a;
        if(value > n) return 0;
        if(dp[n][a] != -1) return dp[n][a];
        int mod = 1e9 + 7;
        return dp[n][a] = (solve(n, x, a+1, dp) + solve(n-value, x, a+1, dp)) % mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends