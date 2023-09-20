/*
Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum 
by using different combinations from coins[ ].  
Note: Assume that you have an infinite supply of each type of coin. And you can use any coin as many times as you want.



Input:
N = 3, sum = 4
coins = {1,2,3}
Output: 4
Explanation: Four Possible ways are: {1,1,1,1},{1,1,2},{2,2},{1,3}.

Input:
N = 4, Sum = 10
coins = {2,5,3,6}
Output: 5
Explanation: Five Possible ways are: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long int dp[1001][1001]; 
    int n;
    long long int helper(int indx, int target, int* coins){

        if (target == 0)
        return 1;
        
        if (indx == n)
        return 0;
        
        if (dp[indx][target] != -1)
        return dp[indx][target];
        
        long long int take = 0, skip = 0;
        if (target >= coins[indx])
        take = helper(indx,target - coins[indx],coins);
        skip = helper(indx+1, target, coins);

        return dp[indx][target] = take + skip;
    }

long long int count(int coins[], int N, int sum) {
    memset(dp,-1,sizeof(dp));
        n = N;
        return helper(0,sum,coins);
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
