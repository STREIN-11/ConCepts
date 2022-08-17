// #include <stdio.h>
// #include <stdlib.h>

// void cal(int ar[],int n,int num){
//     int sum = 0,count=0;
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < n; j++)
//         {
//             sum = sum + ar[i]+ar[j];
//         }
               
//     }
    
// }


// int main(int argc, char const *argv[]){
//     int size,num;
//     printf("Enter Size of Array : ");
//     scanf("%d",&size);
//     int arr[size];
//     printf("Enter Array Elments : ");
//     for (int i = 0; i < size; i++)
//     {
//         scanf("%d",&arr);
//     }
//     printf("Enter The Number : ");
//     scanf("%d",&num);
//     printf("%d",cal(arr,size,num));
    

//     return 0;
// }



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        unordered_map<int,int> op;
        int sum=0;
        int res=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
            if(sum==k)
                res=max(res,i+1);
            if(op.find(sum-k)!=op.end()){
                res=max(res,i-op[sum-k]);
            }
            if(op.find(sum)==op.end())
                op[sum]=i;
        }
        return res;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends