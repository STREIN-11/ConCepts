/*
You are given an array arr of n elements. In one operation you can pick two indices i and j, such that arr[i] >= arr[j] and
 replace the value of arr[i] with (arr[i] - arr[j]). You have to minimize the values of the array after performing any number
 of such operations.




Example 1:
Input:
n = 3
arr = {3,2,4}
Output:
1
Explanation:
1st Operation : We can pick 4 & 3, subtract 4-3 => {3,2,1}
2nd Opeartion : We can pick 3 & 2, subtarct 3-2 => {1,2,1}
3rd Operation : We can pick 1 & 2, subtract 2-1 => {1,1,1}
4th Opeartion : We can pick 1 & 1, subtract 1-1 => {1,0,1}
5th Operation : We can pick 1 & 1, subtract 1-1 => {0,0,1}
After this no operation can be performned, so maximum no is left in the array is 1, so the ans is 1.

Example 2:
Input:
n = 2
arr = {2,4}
Output:
2
Explanation:
1st Operation : We can pick 4 & 2, subtract 4-2 => {2,2}
2nd Operation : We can pick 2 & 2, subtract 2-2 => {0,2}
After this no operation can be performned, so maximum no is left in the array is 2, so the ans is 2.*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
        int mini=*min_element(arr.begin(),arr.end());
       // sort(arr.begin(),arr.end());
       int ans=mini;
         for(int i=0;i<n;i++){
             if(arr[i]%mini){
                 ans=min(ans,arr[i]%mini);
             }
         }
         return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.minimumNumber(n,arr)<<endl;
    }
}
// } Driver Code Ends
