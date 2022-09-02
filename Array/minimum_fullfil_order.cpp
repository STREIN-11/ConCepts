/*
Geek is organizing a party at his house. For the party, he needs exactly N donuts for the guests. Geek decides to order the donuts from a 
nearby restaurant, which has L chefs and each chef has a rank R. 
A chef with rank R can make 1 donut in the first R minutes, 1 more donut in the next 2R minutes, 1 more donut in 3R minutes, and so on.
For example. a chef with rank 2, can make one donut in 2 minutes, one more donut in the next 4 minutes, and one more in the next 6 
minutes. So, it take 2 + 4 + 6 = 12 minutes to make 3 donuts. A chef can move on to making the next donut only after completing the previous one. All the chefs can work simultaneously.
Since, it's time for the party, Geek wants to know the minimum time required in completing N donuts. Return an integer denoting the 
minimum time

Input:
N = 10
L = 4
rank[] = {1, 2, 3, 4}
Output: 12
Explanation: 
Chef with rank 1, can make 4 donuts in time 1 + 2 + 3 + 4 = 10 mins
Chef with rank 2, can make 3 donuts in time 2 + 4 + 6 = 12 mins
Chef with rank 3, can make 2 donuts in time 3 + 6 = 9 mins
Chef with rank 4, can make 1 donuts in time = 4 minutes
Total donuts = 4 + 3 + 2 + 1 = 10 and total time = 12 minutes.*/

//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int maxDonutPos(int n, int sum){
        int a=n, d=n;
        
        double twoAMinusD= (2*a-d);
        double eightDSum= 8*d*sum;
        double twoD= 2*d;
        double top= (-(twoAMinusD) + sqrt(pow(twoAMinusD, 2)+eightDSum) );
        double res = (top/ (2*d));
        
        return res;
    }
    
    int getTotalDonutPos(vector<int> &r, int time){
        int donuts=0;
        
        //apply the formula of sum of Arithmatic progression
        // max time is given find n(max) by formula -> (n/2)(2a+(n-1)d) <= maxTime
        for(int i=0;i<r.size();i++){
            donuts+= maxDonutPos(r[i], time); 
        }
        return donuts;
    }
    
    int findMinTime(int N, vector<int>&A, int L){
        int lo=0, hi=1e7;
        int ans=INT_MAX;
        
        while(lo<=hi){
            int mid= lo+(hi-lo)/2;
            int totalDonutPos= getTotalDonutPos(A, mid);
            if(totalDonutPos<N){
                lo=mid+1;
            } else if(totalDonutPos>=N){
                ans= mid;
                hi=mid-1;
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
	    cin >> n;
	    int l;
	    cin >> l;
	    vector<int>arr(l);
	    for(int i = 0; i < l; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    int ans = ob.findMinTime(n, arr, l);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends