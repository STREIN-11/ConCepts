/*
We have been given N balloons, each with a number of coins associated with it. On bursting a balloon i, the number of coins gained is equal 
to A[i-1]*A[i]*A[i+1].
Also, balloons i-1 and i+1 now become adjacent. Find the maximum possible profit earned after bursting all the balloons. 
Assume an extra 1 at each boundary.

Example 1:





Input: 
N=2
a[]={5, 10}
Output: 
60
Explanation: First Burst 5, Coins = 1*5*10
              Then burst 10, Coins+= 1*10*1
              Total = 60

Input:
N=4
a[] = {3,1,5,8}
Output:
167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167.*/

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        int maxCoins(int N, vector<int>& a) {
            int n = a.size();
            vector<int> A(n+2, 1);
            for(int i = 0; i < n; i++) A[i+1] = a[i];
            vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
            for(int len = 1; len <= n; len++) {
                for(int left = 1; left <= n-len+1; left++) {
                    int right = left + len - 1;
                    for(int i = left; i <= right; i++) {
                        dp[left][right] = max(dp[left][right], A[left-1]*A[i]*A[right+1] + dp[left][i-1] + dp[i+1][right]);
                    }
                }
            }
            return dp[1][n];
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends
