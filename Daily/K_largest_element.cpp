/*
Given an array Arr of N positive integers and an integer K, find K largest elements from the array.  The output elements should be 
printed in decreasing order.

Input:
N = 5, K = 2
Arr[] = {12, 5, 787, 1, 23}
Output: 787 23
Explanation: 1st largest element in the
array is 787 and second largest is 23.

Input:
N = 7, K = 3
Arr[] = {1, 23, 12, 9, 30, 2, 50}
Output: 50 30 23
Explanation: 3 Largest element in the
array are 50, 30 and 23.*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    vector<int>ans;
	    priority_queue<int, vector<int>, greater<int>>pq;
	    for(int i=0; i<n; i++){
	        if(i<k)
	            pq.push(arr[i]);
	        else{
	            if(arr[i]>pq.top()){
	                pq.pop();
	                pq.push(arr[i]);
	            }
	        }
	    }
	    while(!pq.empty()){
	        ans.push_back(pq.top());
	        pq.pop();
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
