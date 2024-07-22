/*
A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top of 
Nth step. As the answer will be large find the answer modulo 1000000007.

Example 1:
Input:
N = 1
Output: 1




Example 2:
Input:
N = 4
Output: 7
Explanation:Below are the 7 ways to reach
4
1 step + 1 step + 1 step + 1 step
1 step + 2 step + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 step
2 step + 2 step
3 step + 1 step
1 step + 3 step
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        vector<long long>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]+=dp[i-1];
            if(i>=2)dp[i]+=dp[i-2];
            if(i>=3)dp[i]+=dp[i-3];
            dp[i]%=1000000007;
        }
        return dp[n];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends
