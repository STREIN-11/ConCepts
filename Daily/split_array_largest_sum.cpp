/*
Given an array arr[] of N elements and a number K. Split the given array into K subarrays such that the maximum subarray 
sum achievable out of K subarrays formed is minimum possible. Find that possible subarray sum.
Input:
N = 4, K = 3
arr[] = {1, 2, 3, 4}
Output: 4
Explanation:
Optimal Split is {1, 2}, {3}, {4}.
Maximum sum of all subarrays is 4,
which is minimum possible for 3 splits. 

Input:
N = 3, K = 2
A[] = {1, 1, 2}
Output:
2
Explanation:
Splitting the array as {1,1} and {2} is optimal.
This results in a maximum sum subarray of 2.*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int splitArray(int arr[] ,int n, int K) {
        // code here
        int l=0,r=0;
        for(int it=0;it<n;it++)
        {
            l=max(arr[it],l);
            r+=arr[it];
        }
        while(l<=r)
        {
            int mid=(l+r)/2;
            int count=0,sum=0;
            for(int i=0;i<n;i++)
            {
                if(sum+arr[i]>mid)
                {
                    sum=0;
                    count++;
                }
                sum+=arr[i];
                if(count>K)
                break;
            }
            if(count<K)
            r=mid-1;
            else
            l=mid+1;
        }
        return l;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends