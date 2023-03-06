/*
Given an non-negative integer n. You are only allowed to make 
set bit unset. You have to find the maximum possible value of
query so that after performing the given operations, no three 
consecutive bits of the integer query are set-bits. 








Input:
n = 2
Output: 
2
Explanation: 
2's binary form is 10, no 3 consecutive set bits are here. 
So, 2 itself would be answer.

Input:
n = 7
Output: 
6
Explanation: 
7's binary form is .....00111.We can observe that 3
consecutive bits are set bits. This is not allowed.
So, we can perfrom the operation of changing set 
bit to unset bit. Now, the number 
becomes 6 that is .....00110. It satifies the 
given condition. Hence, the maximum possible 
value is 6.*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int noConseBits(int n) {
        int ans=0;
        int i=31;
        int count=0;
        while(i>=0)
        {
            if(count<=1 && (n&(1<<i)))
            {
                ans=(ans|(1<<i));
                count++;
            }
            else
            {
                count=0;
            }
            i--;
        }
        return ans;
    }
};
int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}
