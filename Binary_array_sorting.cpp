// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
//User function template for C++

// binArray is an array that consists only 0s and 1s
// return sorted binary array 
class Solution{
    public:
    vector<int> SortBinaryArray(vector<int> binArray)
    {
        // Your code goes here 
        int oneInd = -1;
       for(int ind=0; ind<binArray.size(); ind++)
           if(binArray[ind]==1){
                   oneInd = ind;
                   break;
           }
       if(oneInd==-1)
           return binArray;
       for(int ind=oneInd+1; ind<binArray.size(); ind++)
           if(binArray[ind]==0){
               swap(binArray[ind], binArray[oneInd]);
               oneInd++;
           }
       return binArray;
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> binArray(n);
	    
	    for(int i = 0; i  < n; i++)
	      cin>>binArray[i];
	    Solution ob;  
	  	vector<int> result = ob.SortBinaryArray(binArray);
	  	for(int i=0; i<n; i++)
	  	    cout<<result[i]<<" ";
	      
	    cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends