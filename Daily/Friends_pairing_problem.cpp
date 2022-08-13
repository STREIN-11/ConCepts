//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
#define m 1000000007
class Solution
{
    public:
    // Returns count of ways n people 
    // can remain single or paired up. 
    int countFriendsPairings(int n) 
    { 
        long long a = 1, b = 2, c = 0; 
    	if (n <= 2) { 
    		return n; 
    	} 
    	for (int i = 3; i <= n; i++)
    	{ 
    		// using modular arithmentic properties.
    		c = ( b%m + ( ( (i - 1)%m  *  a%m )%m ) %m )%m ; 
    		a = b; 
    		b = c; 
    	} 
    	return c; 
    }
}; 
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends