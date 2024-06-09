/*
Given a non-negative integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some integer x.
Example 1:
Input: 
N = 8
Output: 
YES
Explanation:
8 is equal to 2 raised to 3 (23 = 8).

Example 2:









Input: 
N = 98
Output: 
NO
Explanation: 
98 cannot be obtained by any power of 2.*/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool isPowerofTwo(long long n){
        if(n==0)
            return false;
        int count = 0;
        while(!count){
            count += (n&1);
            n >>= 1;
        }
        if(n==0)
            return true;
        return false;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;

        Solution ob;
         if(ob.isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}

// } Driver Code Ends
