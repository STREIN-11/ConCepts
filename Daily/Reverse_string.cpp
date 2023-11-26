/*
You are given a string s. You need to reverse the string.
Example 1:
Input:
s = Geeks
Output: skeeG





Example 2:
Input:
s = for
Output: rof*/

#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    string reverseWord(string str)
    {
        stack<char>s;
        string ans;
        for(auto i:str){
            s.push(i);
        }
       while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
        
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends
