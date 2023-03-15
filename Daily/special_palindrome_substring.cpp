/*
Given two strings s1 and s2, The task is to convert s1 into a palindrome such that s1 contain s2 as a substring in a minimum number of operation.
In a single operation, we can replace any word of s1 with any character.
Note: If it is not possible to convert s1 such that it is a palindrome as
well as contains substring of s2, then return -1.



Input:
s1="abaa" s2="bb"
Output: 1
Explanation:
we can replace s1[2]='a' with 'b'.
So the new s1 will be like "abba",
having s2 as a substring.

Input:
s1="abbd" s2="mr"
Output: 4
Explanation:
1st: s1="mrbd" --> 2 operations (this is the 
minimum operation to make s2 a substring of s1) 
2nd: s1="mrrm" --> 2 operations 
(this is the minimum operation to make s1 palindrome)*/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    public:
    
    int specialPalindrome(string s1, string s2){
            //Code Here
            int ans=2000;
            int n=s1.size(),m=s2.size();
            for(int i=0;i<n-m+1;i++){
                vector<bool>changed(n,0);
                int cnt=0;
                string t=s1;
                for(int j=0;j<m;j++){
                    if(t[i+j]!=s2[j]){
                        if(changed[i+j]==0){
                            cnt++;
                            t[i+j]=s2[j];
                        }
                        else{
                            cnt=2000;
                            break;
                        }
                    }
                    if(t[n-(i+j)-1]!=s2[j]){
                         if(changed[n-(i+j)-1]==0){
                            cnt++;
                            t[n-(i+j)-1]=s2[j];
                        }
                        else{
                            cnt=2000;
                            break;
                        }
                    }
                    changed[i+j]=changed[n-(i+j)-1]=1;
                }
                for(int j=0;j<n;j++){
                    if(changed[j]==0 and t[j]!=t[n-j-1]){
                        cnt++;
                        t[j]=t[n-j-1];
                        changed[j]=1;
                        changed[n-j-1]=1;
                    }
                }
                ans=min(ans,cnt);
            }
            return ((ans==2000)?-1:ans);
        }

};

//{ Driver Code Starts.


int main(){
    int t;
    cout<<"How Many Times : ";
    cin>>t;
    while(t--){
        string s1,s2;
        cout<<"Enter 1st String : ";
        cin>>s1;
        cout<<"Enter 2nd String : ";
        cin>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
