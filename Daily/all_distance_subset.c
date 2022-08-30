/*
Input: nums = {1,2}
Output: {0,1,2,3}
Explanation: Four distinct sums can be
calculated which are 0, 1, 2 and 3.
0 if we do not choose any number.
1 if we choose only 1.
2 if we choose only 2.
3 if we choose 1 and 2.*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    set<int> s;
    int dp[101][10001];
    int n;
public:
    int rec(int ind, int sum, vector<int>& nums){
        if(ind == n)    {s.insert(sum); return s.size();}
        if(dp[ind][sum] != -1)   return dp[ind][sum];
        int take = rec(ind+1, sum+nums[ind], nums);
        int nontake = rec(ind+1, sum, nums);
        
        return dp[ind][sum] = take + nontake;
    }
	vector<int> DistinctSum(vector<int>nums){
	    // Code here
	    n = nums.size();
	    memset(dp, -1, sizeof(dp));
	    rec(0, 0, nums);
	    vector<int> res;
	    for(auto val: s)    res.push_back(val);
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends