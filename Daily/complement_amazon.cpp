/*
You are given a binary string str. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and 
complement the characters between L and R i.e strL, strL+1, , strR. By complement, we mean change character 0 to 1 and vice-versa.
You task is to perform ATMOST one operation such that in final string number of 1s is maximised. If there is no need to completement, 
i.e., string contains all 1s, return -1. Else, return the two values denoting L and R. If there are multiple solutions, return
the lexicographically smallest pair of L and R.


Input:
N = 3
str = "111"
Output: -1
Explanation: As all characters are '1', 
so don't need to complement any.

Input:
N = 2
str = "01"
Output: 1 1
Explanation: After complementing [1, 1] 
the string becomes "11"  */

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {

        vector<int> v;

        int count=0;

        for(int i=0;i<n;i++)

        {

            if(str[i]-'0'==1) count++;

        }

        if(count==n) return {-1};

        int max=0,sum=0,p=0,left=0,right=0,s;

        for(int i=0;i<n;i++){

            if(str[i]-'0'==0) s=1;

            else s=-1;

            sum=sum+s;

            if(sum>max) { max=sum; left=p,right=i;}

            else if(sum<0) {p=i+1; sum=0;}

        }

        v.push_back(left+1);

        v.push_back(right+1);

        return v;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends
