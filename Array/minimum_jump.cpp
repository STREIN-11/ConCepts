#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int minJumps(int a[], int n){
    int pos = 0;
    int jump = 0;
    int destination = 0;
    for (int i = 0; i < n-1; i++)
    {
        destination = max(destination, a[i] + i);
        if (pos == i)
        {
            jump++;
            if(destination<=i)
            {
                return -1;
            }
            pos = destination;
        }
    }
        return jump;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends