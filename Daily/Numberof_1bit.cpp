/*
Given a positive integer N, print count of set bits in it. 





Example 1:

Input:
N = 6
Output:
2
Explanation:
Binary representation is '110' 
So the count of the set bit is 2.

Input:
8
Output:
1
Explanation:
Binary representation is '1000' 
So the count of the set bit is 1.*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int setBits(int N) {
        // Write Your Code here
        
        int count = 0;
        
        while(N>0)
        {
            // check the rightmost bit if==1 then increment count
            if(N&1)
            {
                count++;
            }
            
            // divide the number by 2 using rightshift operator
            N= N>>1;
            
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends
