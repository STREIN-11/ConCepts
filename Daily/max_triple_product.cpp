/*
Given an array arr of size n, the task is to find the maximum
 triplet product in the array.




Input:
n = 4
arr[] = {1, 2, 3, 5}
Output:
30
Explanation:
5*3*2 gives 30. This is the maximum possible
triplet product in the array.

Input:
n = 7
arr[] = {-3, -5, 1, 0, 8, 3, -2} 
Output:
120
Explanation: 
-3*-5*8 gives 120. This is the maximum possible triplet product in the array.
*/

//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n){
    sort(arr, arr+n);
    long long a=arr[n-1]*arr[n-2]*arr[n-3];
    long long b=arr[0]*arr[1]*arr[n-1];
    return (long long) max(a,b);
    }
};

int main()
{
	int t;
    cout<<"HOw many Times : ";
	cin>>t;
	while(t--)
	{
	    int n,i;
        cout<<"Enter Length : ";
	    cin>>n; long long arr[n];
		cout<<"Enter Array Elements : ";
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<"Answer : "<<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends
