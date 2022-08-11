#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    
    void solve(vector<int> v, int idx, int k, int &ans) {
        
        //if only one person is left in the vector
        //then he is the survivor
        if(v.size() == 1) {
            ans = v[0];
            return;
        }
        
        //making our problem smaller
        idx = (idx + k) % v.size(); //this person will be killed
        //% operation is done to circle in the linear data structure that is vector
        
        //remove that person from the vector
        v.erase(v.begin() + idx);
        
        //solving for the smaller problem
        solve(v,idx,k,ans);
        
        return;
        
    }
    
    int josephus(int n, int k)
    {
       vector<int> vec;
       for(int i=1;i<=n;i++) {
           vec.push_back(i);
       }
       
       k = k-1; //as we are killing idx + (k-1) th valued person
       int ans = -1;
       
       solve(vec,0,k,ans);
        
       return ans;   
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}