/*
Given a string s containing 0's and 1's. You have to return the smallest positive integer C, such that the binary string can be 
cut into C pieces and each piece should be of the power of 5  with no leading zeros.
Note: The string s is a binary string. And if no such cuts are possible, then return -1.







Input:
s = "101101101"
Output: 
3
Explanation: 
We can split the given string into 
three 101s, where 101 is the binary 
representation of 5.

Input:
s = "00000"
Output: 
-1
Explanation: 
0 is not a power of 5.*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    bool isPowerOfFive(string s) {
    int n = s.length();
    if (n == 0) return false;
    if (s[0] == '0') return false;  
    long long num = 0, p=1;
    for (int i = n-1; i >= 0; i--) {
        if(s[i]=='1'){
            num+=p;
        }
        p=p*2;
    }
    if (num == 0) return false;
    
    while (num > 1) {
        if (num % 5 != 0) return false;
        num /= 5;
    }
    return true;
}
int cuts(string s) {
    int n = s.length();
    if (n == 0 || s[0] == '0')
        return -1;
    if (isPowerOfFive(s))
        return 1;
    int minCuts = INT_MAX;
    for (int i = 1; i < n; i++) {
        string left = s.substr(0, i);
        string right = s.substr(i);
        if (isPowerOfFive(left)) {
            int cutsRight = cuts(right);
            if (cutsRight != -1)
                minCuts = min(minCuts, 1 + cutsRight);
        }
    }
    if (minCuts != INT_MAX)
        return minCuts;
    return -1; 
}
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends
