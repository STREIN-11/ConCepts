/*
Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing.
 
 
 
  
 
 
Input: nums = [1, 2, 5, 3, 2]
Output: 5
Explanation: The sequence {1, 2, 5} is
increasing and the sequence {3, 2} is 
decreasing so merging both we will get 
length 5.

Input: nums = [1, 11, 2, 10, 4, 5, 2, 1]
Output: 6
Explanation: The bitonic sequence 
{1, 2, 10, 4, 2, 1} has length 6.*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	int n = nums.size();
	    // First find the Longest Increasing Subsequence:
	    vector<int> lis(n,1);
	    
	    for(int i=1; i<n; ++i) {
	        for(int j=0; j<i; ++j) {
	            if(nums[i] > nums[j]) {
	                lis[i] = max(lis[i], 1+lis[j]);
	            }
	        }
	    }
	    
	    // Now Find the Longest decreasing subsequence ending at i'th index
	    vector<int> lds(n,1);
	    
	    for(int i=n-2; i>=0; --i) {
	        for(int j=n-1; j>i; --j) {
	            if(nums[i] > nums[j]) {
	                lds[i] = max(lds[i], 1+lds[j]);
	            }
	        }
	    }
	    
	    int maxi = INT_MIN;
	    
	    for(int i=0; i<n; ++i) {
	        maxi = max(maxi, (lis[i]+lds[i]-1));
	        // -1 is done in order to eliminate the i'th element once, which is included twice
	    }
	    
	    return maxi;
	    
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
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
