/*
Given the maximum occurrences of a, b, and c in a string. Your task is to make the string containing only 
a, b, and c such that no three consecutive characters are the same. If the resultant string equals to a+b+c, 
return the length (a+b+c) otherwise -1.




Example 1:
Input:
a = 3, b = 3, c = 3
Output: 
9
Explanation: 
No three consecutive character of
the string "abcabcabc" is same.

Example 2:
Input:
a = 11, b = 2, c = 2
Output: 
-1
Explanation: 
If we build a string of these character's,
the string will be"aabaacaabaacaaa", here
we can see that there will be three consecutive a. So
there is no solution exist.*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        vector<int> v={a,b,c};
       sort(v.begin(),v.end());
       int ans=-1;
       
       if(v[2]>(2*(v[0]+v[1])+2))return -1;
       else ans=a+b+c;
       
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
