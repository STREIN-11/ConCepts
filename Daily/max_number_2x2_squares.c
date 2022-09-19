/*
Given the base (in units) of a right-angled isoceles traingle, find the maximum number of 2X2 squares that can fit in the triangle
with given base.
nput: 8
Output: 6
Explanation:
Please refer below diagram for explanation.
squares-in-triangle
https://practice.geeksforgeeks.org/problems/maximum-number-of-22-squares/1
*/
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long int numberOfSquares(long long int base)
    {
        base = base/2 - 1;

        long long int ans = base*(base+1)/2;

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		long long int base;
		cin >> base;

        Solution ob;
		cout << ob.numberOfSquares(base) << "\n";

	}

	return 0;
}

// } Driver Code Ends