//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        int rs=0,cs=0,re=R,ce=C;
        int count=0;

        vector<int> v;
        while(count<R*C){

            for(int i=cs;i<ce;i++){

                v.push_back(a[rs][i]);

                count++;

            }

            

            for(int i=rs+1;i<re;i++){

                v.push_back(a[i][ce-1]);

                count++;

            }

            if(re-rs-1>0)

            for(int i=ce-2;i>=cs;i--){

                v.push_back(a[re-1][i]);

                count++;

            }

            if(ce-cs-1>0)

            for(int i=re-2;i>rs;i--){

                v.push_back(a[i][cs]);

                count++;

            }

            rs++;re--;cs++;ce--;

        }

        reverse(v.begin(),v.end());

        return v;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
