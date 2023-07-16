/*
Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, 
you have to tell which character has appeared only once in the stream upto that point. If there are many characters that 
have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character 
then append '#' to the answer.


Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'

Input: A = "zz"
Output: "z#"
Explanation: For every character first non
repeating character is as follow-
"z" - first non-repeating character is 'z'
"zz" - no non-repeating character so '#'*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    string ans;
		    int n=s.size();
		    map<char,int>mp;
		    queue<char>q;
		    for(int i=0;i<n;i++){
		        mp[s[i]]++;
		        q.push(s[i]);
		        while(!q.empty() && mp[q.front()]>1){
		            q.pop();
		        }
		        if(!q.empty()){
		            ans+=q.front();
		        }else{
		            ans+='#';
		        }
		    }
		    return ans;
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
