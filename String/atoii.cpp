#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int s = str.size(), temp =0, flag = 0;
       if(str[0] == '-')
       flag = 1;
       for(int i=0;i<s; i++)
       { if(flag== 1 && i==0)
           continue;
          
         if(str[i]>57 ||( str[i]<48))
         return -1;
         else {
         int c = str[i] -48;
         temp = temp*10 + c;
         }
       }
       if(flag){
           return -1*temp;
       }
       return temp;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends