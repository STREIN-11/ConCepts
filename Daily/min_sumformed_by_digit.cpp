#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        long int akt=0, nr=0;
        sort(arr, arr+n); 
        for(int i=0;i<n;i++){
            if(i%2==0){
                akt=akt*10+arr[i];
            }
            else{
                nr=nr*10+arr[i];
            }
        }
        return (akt+nr); 
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
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends