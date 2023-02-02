/*
Given a positive number n. You need to write a program to find the maximum sum of distinct numbers such that the LCM of all 
these numbers is equal to n.
Input: n = 2
Output: 3 




Explanation: The distinct numbers you can have are 
just 1 and 2 and their sum is equal to 3.
Input: n = 5
Output: 6
Explanation: The distinct numbers you can have 
are just 1 and 5 and their sum is equal to 6. */
//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long int maxSumLCM(int n) 

    {

        // code here

        // nothing but sum of all factor's of a number.

        long long int ans=0,i;

        for(i=1;i<=sqrt(n);i++)

        {

            if(n%i == 0 && n/i!=i)

            {

                ans+=n/i;

                ans+=i;

            }

            else if (n%i == 0 && n/i == i)

            ans+=i;

        }

        // cout<<ans;

        return ans;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.maxSumLCM(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
