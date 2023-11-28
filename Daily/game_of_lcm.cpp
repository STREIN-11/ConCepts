/*
Given an integer N. Find maximum LCM (Least Common Multiple) that can be obtained from four numbers less than or equal to N.
Note: Duplicate numbers can be used.




Input:
N = 4
Output: 12
Explanation:
The four numbers can be [4,4,3,2] or
[4,4,4,3], etc. It can be shown that 12 is
the maximum LCM of four numbers that can
be obtained from numbers less than or equal 
to 4.

Input:
N = 5
Output: 60
Explanation:
The four numbers can be [5,5,4,3] or
[5,4,3,2], etc. 60 is the maximum that can
be obtained.*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(long long n) {
        long long a1 = n;
        int include=0;
        for(long long i=n-1;i>=1;i--) {
            long long g = gcd(a1,i);
            if(g==1) {
                a1*=i;
                include++;
            }
            if(include==3) return a1;
        }
        return a1;
    }
    
    long long maxGcd(int N) {
        // code here
        return max(solve(N),solve(N-1));
    }
    
    long long gcd(long long a,long long b) {
        if(a==0) return b;
        return gcd(b%a,a);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends
