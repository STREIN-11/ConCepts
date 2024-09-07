/*
Given an array arr[] of n positive integers. The task is to find the maximum of j - i subjected to the constraint of arr[i] <= arr[j].







Input:
n = 9
arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output: 
6
Explanation: 
In the given array arr[1] < arr[7]  satisfying 
the required condition (arr[i] <= arr[j])  thus 
giving the maximum difference of j - i which is
6(7-1).

Input:
N = 2
arr[] = {18, 17}
Output: 
0
Explanation: 
We can either take i and j as 0 and 0 
or we cantake 1 and 1 both give the same result 0.*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int A[], int N) {
   int left[N];
   int right[N];
   left[0]=A[0];
   right[N-1]=A[N-1];
   for(int i=1;i<N;i++){
       left[i]=min(left[i-1],A[i]);
   }
   for(int i=N-2;i>=0;i--){
       right[i]=max(right[i+1],A[i]);
   }
   int maxi=INT_MIN;
   int i=0,j=0;
   
   while(i<N&&j<N){
       if(left[i]<=right[j]){
           maxi=max(maxi,j-i);
           j++;
       }
       else{
       i++;
       }
   }
   return maxi;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
