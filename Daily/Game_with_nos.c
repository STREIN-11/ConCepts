/*
Input : n=5, arr[ ] = {10, 11, 1, 2, 3}
Output : 1 10 3 1 3
Explanation:
At index 0, arr[0] xor arr[1] = 1
At index 1, arr[1] xor arr[2] = 10
At index 2, arr[2] xor arr[3] = 3
...
At index 4, No element is left So, it will remain as
it is.
New Array will be {1, 10, 3, 1, 3}.*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


int* game_with_number(int arr[], int n);

int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        int *arr2;
        
        arr2 = game_with_number(arr, n);
        for(int i = 0;i < n; i++)
            cout << arr2[i] << " ";
        
        cout << endl;
        
    }

}

// } Driver Code Ends


int* game_with_number(int arr[], int n)
{
    
    // Complete the function
    for(int i=0;i<n-1;i++)
    {
        arr[i]=arr[i]^arr[i+1];
    }
    
    return arr;
    
}
