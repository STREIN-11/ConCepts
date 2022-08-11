#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string s1,s2;
        for(auto x : str)
        {
            if(x>='a' && x<='z')
            s1.push_back(x);
            else
            s2.push_back(x);
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        
        string ans;
        
        for(auto x : str)
        {
            if(x>='a' && x<='z')
            {
                ans.push_back(s1[0]);
                s1.erase(s1.begin());
            }
            else
            {
                ans.push_back(s2[0]);
                s2.erase(s2.begin());
            }
        }
        return ans;
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}