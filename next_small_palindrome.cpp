// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	string makePalindrome(string in) {
        int a = 0;
        int b = in.size() - 1;
        while (a < b) {
            in[b] = in[a];
            a++;
            b--;
        }
        return in;
    }

    string solve(string A) {
        int n = A.size();
        string temp = makePalindrome(A);
        if (temp > A) return temp;
        int carry = 1;
        for (int a = (n - 1) / 2; a >= 0; a--) {
            int t = A[a] - '0' + carry;
            if (t == 10) {
                t = 0;
                carry = 1;
            } else carry = 0;
            A[a] = '0' + t;
        }
        string res;
        if (carry == 1) res = "1";
        res += A;
        return makePalindrome(res);
    }

    vector<int> generateNextPalindrome(int num[], int n) {
        // code here
        string A;
        for (int i = 0; i < n; i++)A += num[i] + '0';
        string res = solve(A);

        vector<int> ans;
        for (auto i: res)ans.push_back(i - '0');
        return ans;
    }

};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends