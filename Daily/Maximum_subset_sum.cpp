/*
Given an array A of size N. Find the maximum subset-sum of elements that you can make from the given array such that for 
every two consecutive elements in the array, at least one of the elements is present in our subset. 







Input: 
N = 4
A[] = {1, -1, 3, 4}
Output: 8
Explanation: 
We can choose 0th,2nd & 3rd index(0 based 
Index),so that it can satisfy the 
condition & can make maximum sum 8. 

Input: 
N = 3
A[] =  {0, 2, 0};
Output: 2
Explanation: 
We can choose 1st index. Here the 
maximum possible sum is 2.*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long findMaxSubsetSum(int N, vector<int> &A) {
        vector<vector<long long>> dp(N , vector<long long>(2));
        
        // dp[i][0] dont take ith element;
        // dp[i][1] take the ith element;
        dp[0][0] = 0;
        dp[0][1] = A[0];
        
        for(int i=1 ; i<N ; i++){
            dp[i][0] = dp[i-1][1];
            dp[i][1] = A[i]+max(dp[i-1][0] , dp[i-1][1]);
        }
        
        return max(dp[N-1][0] , dp[N-1][1]);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
