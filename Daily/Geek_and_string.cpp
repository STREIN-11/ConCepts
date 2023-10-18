#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[]){
 map<string,int>m;

        for(int i=0;i<N;i++){

            string s="";

            for(int j=0;j<li[i].size();j++){

                s+=li[i][j];

                m[s]++;

            }

        }

         vector<int>v;

        for(int i=0;i<Q;i++){

            v.push_back(m[query[i]]);

        }

         return v;

}
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int Q, N, i = 0, x;
	    cin>>N;
	    string s;
	    string li[N];
	    for(int i = 0;i < N;i++)
	        cin>>li[i];
	    cin>>Q; 
	    x = Q;
	    string query[Q];
	    while(Q--){
	        cin>>s;
	        query[i++] = s;
	    }
	    
	    Solution ob;
	    vector<int> ans = ob.prefixCount(N, x, li, query);
	    for(auto i: ans) 
	        cout<<i<<"\n";
    }
    return 0;
}
// } Driver Code Ends
