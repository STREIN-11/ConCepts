/*
Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum 
of every pair is divisible by k.

Input : arr = [9, 5, 7, 3], k = 6
Output: True
Explanation: {(9, 3), (5, 7)} is a 
possible solution. 9 + 3 = 12 is divisible
by 6 and 7 + 5 = 12 is also divisible by 6.

Input : arr = [2, 4, 1, 3], k = 4
Output: False
Explanation: There is no possible solution.*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        int const constlen{nums.size()};
        int len = nums.size();
        int cnt = 0;
        for (int i = 1 ; i < len ; i++){
            if ((nums[0] + nums[i])%k == 0){ 
                len--; swap(nums[len], nums[i]); nums.pop_back();
                len--; swap(nums[len], nums[0]); nums.pop_back();
                i = 0;
                cnt++;
            }  
        }
        return cnt*2 == constlen ? 1 : 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends