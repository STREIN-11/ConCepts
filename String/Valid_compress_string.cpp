/*
Input:
S = "GEEKSFORGEEKS"
T = "G7G3S"
Output:
1
Explanation:
We can clearly see that T is a valid 
compressed string for S.

Example 2:
Input:
S = "DFS"
T = "D1D"
Output :
0
Explanation:
T is not a valid compressed string.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int checkCompressed(string s, string t) {
        int i=0,j=0;
        string idx="";
        while(i<t.length()){
            if(isupper(t[i])){
                if(idx.length()!=0){
                    string a=idx;
                    j=j+stoi(a);
                    idx="";
                }
                if(s[j]!=t[i])return 0;
                i++;
                j++;
            }
            else{
                idx=idx+t[i];
                i++;
            }
        }
        if(idx.length()==0)return 1;
        if(s.length()-j==stoi(idx))return 1;
        return 0;
    }
};

int main() {
    int t;
    cout<<"How many time : ";
    cin >> t;
    while (t--) {
        string S,T;
        cout<<"Enter String : ";
        cin>>S;
        cout<<"Enter String : ";
        cin>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends