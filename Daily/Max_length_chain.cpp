//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
class Solution{
public:
    /*You are required to complete this method*/
    static bool comp(struct val a, struct val b)
    {
        if(a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    }
    int maxChainLen(struct val p[],int n){
        sort(p, p+n, comp);
        int ans = 1;
        int last = p[0].second;
        for(int i=1; i<n; i++)
        {
            if(p[i].first <= last)
                last = min(last, p[i].second);
            else
             {
                 ans++;
                 last = p[i].second;
             }
            // ans = max(ans, curr);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends