/*
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. 
Determine the fewest cuts needed for palindrome partitioning of the given string.

Example 1:
Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".

Example 2:
Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".*/




#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int palindromicPartition(string s)
    {
        int n=s.length();
        vector<vector<bool>>isPalindrome(n+1,vector<bool>(n+1,0));
        for(int i=0;i<n;i++)
        {
            isPalindrome[i][i]=1;
        }
        for(int gap=1;gap<n;gap++)
        {
            for(int i=0;i<n-gap;i++)
            {
                int j=i+gap;
                if(gap==1)
                {
                    if(s[i]==s[j])
                    isPalindrome[i][j]=1;
                }
                else
                {
                    if((isPalindrome[i+1][j-1]==1) && s[i]==s[j])
                    isPalindrome[i][j]=1;
                }
            }
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        function<int(int,int)>f=[&](int i,int prev)->int{
           if(i==n-1)
           {
               if(isPalindrome[prev][i])
               return 0;
               else
               return 0x3f3f3f3f;
           }
           if(dp[i][prev]!=-1)
           return dp[i][prev];
           int x1=f(i+1,prev);
           int x2=INT_MAX;
           if(isPalindrome[prev][i])
           {
               x2=1+f(i+1,i+1);
           }
           int res=min(x1,x2);
           return dp[i][prev]=res;
        };
        return f(0,0);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
