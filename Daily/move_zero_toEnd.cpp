/*
Given an array arr[] of n positive integers. Push all the zeros of the given array to the right end 
of the array while maintaining the order of non-zero elements. Do the mentioned change in the array in-place.

Example 1:
Input:
N = 5
Arr[] = {3, 5, 0, 0, 4}
Output: 3 5 4 0 0
Explanation: The non-zero elements
preserve their order while the 0
elements are moved to the right.




Example 2:
Input:
N = 4
Arr[] = {0, 0, 0, 4}
Output: 4 0 0 0
Explanation: 4 is the only non-zero
element and it gets moved to the left.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    
	    int count = 0;
	    
	    for(int i=0;i<n;i++)
	        if(arr[i] != 0)
	            arr[count++] = arr[i];
	    
	    while(count < n)
	        arr[count++] = 0;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
