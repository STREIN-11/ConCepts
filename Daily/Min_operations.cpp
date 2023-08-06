/*Given two numbers a and b. In one operation you can pick any non negative integer x and either of a or b. Now if you picked a then
 replace a with a&x else if you picked b then replace b with b&x.
Return the minimum number of operation required to make a and b equal.
Note: Here & represents bitwise AND operation.





Input:
a = 5, b = 12
Output:
2
Explanantion:
In first operation replace 
a = a&4 = 4
after that replace 
b = b&6 = 4
Hence both are same after applying two
operations.

Input: 
a = 100, b = 100
Output: 
0
Explanation: 
Already same.*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int a, int b) {
        if(a==b)
        return 0;
        
        if(a==0 || b==0)
        return 1;
        
        int x = a&b;
        if(a==x || b==x)
        return 1;
        
        return 2;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.solve(a, b);
        
        printf("%d\n", res);
        
    }
}

// } Driver Code Ends
