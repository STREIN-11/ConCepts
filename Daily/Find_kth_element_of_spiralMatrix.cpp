/*
Given a matrix with n rows and m columns. Your task is to find the kth element which is obtained while traversing the matrix spirally. You need to 
complete the method findK which takes four arguments the first argument is the matrix A and the next two arguments will be n and m denoting the size of 
the matrix A and then the forth argument is an integer k. The function will return the kth element obtained while traversing the matrix spirally.



Input:
n = 4, m = 4, k = 10
A[][] = {{1  2  3  4},
         {5  6  7  8},
         {9  10 11 12},
         {13 14 15 16}}
Output:
13
The spiral order of matrix will look like 1->2->3->4->8->12->16->15->14->13->9->5->6->7->11->10. So the 10th element in this order is 13. 

Input:
n = 3, m = 3, k = 4
A[][] = {{1 2 3},
         {4 5 6},
         {7 8 9}}
Output:
6
Explanation:
The spiral order of matrix will look like 1->2->3->6->9->8->7->4->5. So the 4th element in this order is 6.*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		int top = 0, bottom = n - 1, left = 0, right = m - 1;
    int direction = 0; // 0: left to right, 1: top to bottom, 2: right to left, 3: bottom to top

    while (top <= bottom && left <= right) {
        if (direction == 0) {
            for (int i = left; i <= right; i++) {
                k--;
                if (k == 0)
                    return a[top][i];
            }
            top++;
            direction = 1;
        } else if (direction == 1) {
            for (int i = top; i <= bottom; i++) {
                k--;
                if (k == 0)
                    return a[i][right];
            }
            right--;
            direction = 2;
        } else if (direction == 2) {
            for (int i = right; i >= left; i--) {
                k--;
                if (k == 0)
                    return a[bottom][i];
            }
            bottom--;
            direction = 3;
        } else if (direction == 3) {
            for (int i = bottom; i >= top; i--) {
                k--;
                if (k == 0)
                    return a[i][left];
            }
            left++;
            direction = 0;
        }
    }

    return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends
