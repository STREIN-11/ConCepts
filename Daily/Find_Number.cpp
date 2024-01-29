/*
Given an integer N, You need to find the Nth smallest number which only contains odd digits i.e. 1,3,5,7,9 means no even
 digits are allowed on that number (12 will not consider). For example, the starting numbers which only contain odd digits
 are 1,3,5,7,9,11,13,15,17,19,31,33,35 and so on.

Input:
N=3
Output:
5
Explanation:
First three numbers are 1, 3, 5.
Here 5 is the 3rd number, where contains
only odd digits.

Input:
N=13
Output:
35
Explanation:
First 13 numbers are 1,3,5,7,9,
11,13,15,17,19,31,33,35, here 35 
is the answer.*/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long n){
        long long ans = 0;
        vector<int> base5;
        while(n > 0) {
            n--, base5.push_back(n%5);
            n /= 5;
        }
        for(int i = base5.size()-1; i >= 0; i--) {
            ans = ans*10 + 2*base5[i] + 1;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
