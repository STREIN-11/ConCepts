//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    char firstRep (string s)
    {
        //code here.
        int arr[26]={0};
        for(char c: s)
        arr[c-'a']++;
        
        for(int i=0;i<s.size();i++)
        {if(arr[s[i]-'a']>1)
        return s[i];}
        
        return '#';
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        char res = ob.firstRep (s);
        if (res == '#') cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends
