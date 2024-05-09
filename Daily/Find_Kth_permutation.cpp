/*
Given two integers N (1<=N<=9) and K. Find the kth permutation sequence of first N natural numbers. Return the answer in string format.

Input: N = 4, K = 3
Output: 1324
Explanation: 
Permutations of first 4 natural numbers:
1234,1243,1324,1342,1423,1432.....
So the 3rd permutation is 1324. 

Input: N = 3, K = 5
Output: 312
Explanation: 
Permutations of first 3 natural numbers:
123,132,213,231,312,321.
So the 5th permutation is 312. */

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        k=k-1;
        vector<string> v;
        for(int i=1;i<=n;i++){
            string c=to_string(i);
            v.push_back(c);
        }
        vector<int> fact(n,1);
        for(int i=1;i<n;i++){
            fact[i]=fact[i-1]*i;
        }
        string s;
        for(int i=n-1;i>=0;i--){
            int ind=k/fact[i];
            s+=v[ind];
            v.erase(v.begin()+ind);
            k=k%fact[i];
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
