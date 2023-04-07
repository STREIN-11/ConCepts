/*
Given an array of positive and negative integers. You have to make the array beautiful. An array is beautiful if two adjacent integers,
arr[i] and arr[i+1] have the same sign. And you can do the following operation any number of times until the array becomes beautiful.
If two adjacent integers have different signs, remove them.
Return the beautiful array after performing the above operation.









Note: An empty array is also a beautiful array. There can be many adjacent integers with different signs. So remove adjacent 
integers with different signs from left to right.

Example 1:
Input: 4 2 -2 1
Output: 4 1
Explanation: As at indices 1 and 2 , 2 and -2 have
different sign, they are removed. And the  the final
array is: 4 1.

Example 2:
Input: 2 -2 1 -1
Output: []
Explanation: As at indices 0 and 1, 2 and -2 have
different sign, so they are removed. Now the array
is 1 -1.Now 1 and -1 are also removed as they have
different sign. So the final array is empty. */

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
    vector<int> ans;
    stack<int> pos,neg;
    for(auto &x:arr){
        if(x>=0){
            if(neg.size())
            neg.pop();
            else
            pos.push(x);
        }
        else{
            if(pos.size())
            pos.pop();
            else
            neg.push(x);
        }
    }
    while(!pos.empty()){
        ans.push_back(pos.top());
        pos.pop();
    }
    while(!neg.empty()){
        ans.push_back(neg.top());
        neg.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends
