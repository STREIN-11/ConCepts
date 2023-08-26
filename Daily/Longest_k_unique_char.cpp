/*
Given a string you need to print the size of the longest possible substring that has exactly K unique characters. 
If there is no possible substring then print -1.

Example 1:
Input:
S = "aabacbebebe", K = 3
Output: 
7
Explanation: 
"cbebebe" is the longest substring with 3 distinct characters.

Example 2:
Input: 
S = "aaaa", K = 2
Output: -1
Explanation: 
There's no substring with 2 distinct characters.*/

#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int longestKSubstr(string s, int k) {
    int n = s.size();

    // Check if the string size is less than k
    if(n < k) {
        return -1;
    }

    unordered_map<char, int> char_freq;
    int start = 0, end = 0, max_len = -1;

    while(end < n) {
        // Add current character to char_freq map
        char_freq[s[end]]++;

        // If the number of unique characters in the map becomes more than k
        // then shrink the window from left
        while(char_freq.size() > k) {
            char_freq[s[start]]--;
            if(char_freq[s[start]] == 0) {
                char_freq.erase(s[start]);
            }
            start++;
        }

        // Update the max_len if the current window size is greater 
        // and we have exactly k unique characters
        if(char_freq.size() == k) {
            max_len = max(max_len, end - start + 1);
        }

        end++;
    }

    // If no substring found with k unique characters
    if(max_len == -1) {
        return -1;
    }

    return max_len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
