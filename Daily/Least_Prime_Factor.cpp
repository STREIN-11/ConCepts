/*
Given a number N, find the least prime factors for all numbers from 1 to N.  The least prime factor of an integer X is the smallest prime 
number that divides it.
Note :

1 needs to be printed for 1.
    You need to return an array/vector/list of size N+1 and need to use 1-based indexing to store the answer for each number.

Input: N = 6
Output: [0, 1, 2, 3, 2, 5, 2] 
Explanation: least prime factor of 1 = 1,
least prime factor of 2 = 2,
least prime factor of 3 = 3,
least prime factor of 4 = 2,
least prime factor of 5 = 5,
least prime factor of 6 = 2.
So answer is[1, 2, 3, 2, 5, 2]. 

Input: N = 4
Output: [0, 1, 2, 3, 2]
Explanation: least prime factor of 1 = 1,
least prime factor of 2 = 2,
least prime factor of 3 = 3,
least prime factor of 4 = 2.
So answer is[1, 2, 3, 2]. */

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> ans;
    void seive(int n)
    {
        ans[1]=1;
        for(int i=2;i*i<= n;i++)
        {
            if(ans[i]^0) continue;
            ans[i]=i;
            for(int j= i*i;j<=n;j+=i)
            {
                if(ans[j] ==0)
                    ans[j]=i;
            }
        }
    }
    vector<int> leastPrimeFactor(int n) {
        // code here
        n++;
        ans.resize(n,0);
        seive(n);
        for(int i=2;i<=n;i++)
            if(ans[i]==0) ans[i]=i;
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends
