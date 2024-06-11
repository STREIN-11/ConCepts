/*
You are given an array a and you need to generate an array b. You are allowed to apply only one type of operation 
on the array a, any number of times. In one operation you can swap ai, ai+1 if ai+ai+1 is even.
Array b should be generated after applying the above operation any number of times on array a and array b should be
 lexicographically the largest among all arrays that can be generated from array a, after applying the above 
operation any number of times.



Input:
N=3
a[]={1,3,5}
Output:
5,3,1
Explanation: [1,3,5],[1,5,3],[3,1,5],[3,5,1],
[5,1,3] and [5,3,1] are all possible
values of array b while the last one is 
lexicographically largest.

Input:
N=4
a[]={1,3,4,2}
Output:
b[]={3,1,4,2}
Explanation: [1,3,4,2],[1,3,2,4],[3,1,2,4] and 
[3,1,4,2] are all possible values of b among 
which the last one is lexicographically largest one.*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
        int low=0,high=1;
            while(low<n && high <n){
                if((a[high-1]+a[high])%2==0){
                    high++;
                    // cout<< high<< endl;
                }else{
                    sort(a.begin()+low,a.begin()+high,greater<int>());
                    low=high;
                    high+=1;
                }
            }
            if(high-low>0){
                sort(a.begin()+low,a.begin()+high,greater<int>());

            }
            return a;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
