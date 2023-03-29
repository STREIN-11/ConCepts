/*
You are given an array A of size N. Let us denote S as the sum of all integers present in the array. Among all integers present 
in the array, find the minimum integer X such that S ≤ N*X.







Input:
N = 3,
A = { 1, 3, 2}
Output:
2
Explanation:
Sum of integers in the array is 6.
since 6 ≤ 3*2, therefore 2 is the answer.

Input:
N = 1,
A = { 3 }
Output:
3
Explanation:
3 is the only possible answer*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
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
    int minimumInteger(int N, vector<int> &A) 
    {
        long long sum = 0 ;
        for (auto i : A)
            sum += i;
        
        int res = INT_MAX;
        float find = sum/(float)N;
        
        for(auto i : A)
            if(find  <= (float)i && i < res)
                res = i;
        
        return res;
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
        Array::input(A,N);
        
        Solution obj;
        int res = obj.minimumInteger(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
