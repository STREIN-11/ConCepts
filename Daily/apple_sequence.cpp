/*
There is a string of size n containing only 'A' and 'O' . 'A' stands for Apple, 'O' stands for Orange. We have m number of spells, 
each spell allows us to convert an orange into an apple.
Find the longest sequence of apples you can make, given an string and the value of m.
Input:
N = 5
M = 1
arr[] = 'AAOAO'
Output: 4 
Explanation: Changing the orange at 
3rd position into an apple gives 
us the maximum possible answer.

Input:
N = 5
M = 1
arr = 'AOOAO'
Output: 2
Explanation: Changing any orange into 
an apple will give us a sequence 
of length 2.*/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
     int appleSequences(int n, int m, string a){

       int p1=0,p2=0,ans=0,count=0;

       while(p1<n){

           if(count<=m){

               if(a[p1++]=='O')count++;

           }

           else{

               if(a[p2++]=='O') count--;

           }

            if(count<=m) ans=max(p1-p2,ans);

       }

   return ans; }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends