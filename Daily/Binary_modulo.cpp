/*
You are given a binary string s and an integer m. You need to return an integer r. Where r = k%m, k is the binary equivalent of string s.





Input:
s = "101" 
m = 2
Output:
1
Explanation: Here k=5 because (101)2 = (5)10.
Hence 5 mod 2 = 1.

Input:
s = "1000"
m = 4
Output:
0
Explanation: Here k=8 and m=4 hence 
r = k mod m = 8 mod 4 = 0.*/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    int expo(int a, int b, int m){
        int ans = 1;
        
        while(b){
            bool bit = b&1;
            if(bit){
                ans = (ans*a)%m;
            }
            
            a = (a*a)%m;
            b >>= 1;
        }
        
        return ans;
    }
    public:
        int modulo(string s,int m)
        {
            int num = 0, a = 1, n = s.size();
            for(int i = n-1; i >= 0; i--){
                if(s[i] == '1'){
                    // TC for exponentiation is log n
                    // num = (num + expo(2, n-1-i, m))%m;
                    num = (num+a)%m;
                }
                // optimise to O(1) from log n
                a = (a*2)%m;
            }
            
            return num%m;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends
