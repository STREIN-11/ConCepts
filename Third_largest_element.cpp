// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int thirdLargest(int a[], int n)
    {
        if(n>=3)
        {
        sort(a,a+n);
        int temp[n],j=0;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]!=a[i+1])
               temp[j++] = a[i];
        }
        temp[j++] = a[n-1];
        
       for (int i=0; i<j; i++)
           a[i] = temp[i];
        
        return a[j-3];
        }
        
        else
           return -1;
    }

};
// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution obj;
	    cout<<obj.thirdLargest(a,n)<<endl;
    }
} 
// } Driver Code Ends
