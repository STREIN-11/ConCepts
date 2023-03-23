/*
Given a string S which consists of only lower case English alphabets, 
you have to perform the below operations:
If the string S contains any repeating character, remove the first
repeating character and reverse the string and again perform the 
above operation on the modified string, otherwise, you stop.
You have to find the final string.

Input: S = "abab"
Output: ba
Explanation:
In 1st operation: The first non repeating 
character is a. After Removing the first 
character, S = "bab". After Reversing the 
string, S = "bab".
In 2nd operation: The first non repeating 
character is b. After Removing the first 
character, S = "ab". After Reversing the 
string, S = "ba".
Now the string S does not contain any 
repeating character.*/

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        string ans1="",ans2="";
        map<char,int>mp;
        for(int i=0; i<s.size(); i++)
        mp[s[i]]++;
        int c=0,i=0,j=s.size()-1;
         while(i <= j)
        {
            if(c%2 == 0)
            {
                if(mp[s[i]]!=1)
                {
                    mp[s[i]]--;
                    c++;
                }
                else
                ans1+=s[i];
                i++;
            }
            else
            {
                if(mp[s[j]] > 1)
                {
                    mp[s[j]]--;
                    c++;
                }
                else 
                ans2=s[j]+ans2;
                j--;
            }
        }
        ans1=ans1+ans2;
        if(c%2)
        reverse(ans1.begin(),ans1.end());
        return ans1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cout<<"How Many times : ";
    cin >> t;
    while (t--) {
        cout<<"Enter String : ";
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends