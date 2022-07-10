// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int x = __builtin_popcount(a), 
        y = __builtin_popcount(b), c = x-y, k = 0;
    int i = (c < 0) ? 1 : -1, j = (c < 0) ? 0 : 1;
    while(c){
        if(((a>>k)&1) == j){
            if(j == 1) a ^= (1<<k);
            else       a |= (1<<k);
            c += i;
        }
        k += 1;
    }
    return a;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends
