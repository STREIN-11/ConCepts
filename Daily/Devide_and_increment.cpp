/*
Given two integers N and K, the task is to count the number of ways to divide N into K groups of positive integers 
such that their sum is N and the number of elements in groups follows a non-decreasing order (i.e. group[i] <= group[i+1]).

Input:
N = 8
K = 4
Output:
5
Explanation:
There are 5 groups such that their sum is 8 
and the number of positive integers in each 
group is 4. The 5 groups are [1, 1, 1, 5], 
[1, 1, 2, 4], [1, 1, 3, 3], [1, 2, 2, 3] and 
[2, 2, 2, 2].

Input: 
N = 4
K = 3
Output:
1
Explanation: 
The only possible grouping is {1, 1, 2}. Hence,
the answer is 1 in this case.*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dp[101][101][101];
    int solve(int i,int cnt,int sum,int n,int k,vector<int>&a){
        if(cnt>k)return 0;
        if(sum>n)return 0;
        if(i>=n){
            if(cnt==k&&sum==n)return 1;
            return 0;
        }
        if(dp[i][cnt][sum]!=-1)return dp[i][cnt][sum];
        int ans=0;
        ans+=solve(i+1,cnt,sum,n,k,a);
        if((sum+a[i])<=n);
        ans+=solve(i,cnt+1,sum+a[i],n,k,a);  
        return dp[i][cnt][sum]=ans;
    }
    int countWaystoDivide(int n,int k) {
        vector<int>a(n);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)a[i]=i+1;
        return solve(0,0,0,n,k,a);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends
