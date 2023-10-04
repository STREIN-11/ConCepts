/*
Given a string in roman no format (s)  your task is to convert it to an integer . 
Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:
Input:
s = V
Output: 5

Example 2:
Input:
s = III 
Output: 3*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int romanToDecimal(string &str) {
        int result =0;
        map<char,
        int>mp
        {
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},
            {'D',500},{'M',1000}
            
        };
        for(int i=0;i<str.length();i++)
        {
            if(mp[str[i]]<mp[str[i+1]])
            {
                result-=mp[str[i]];
            }
            else
            {
                result+=mp[str[i]];
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends
