/*
Input: N = 40321
Output: 18
Explanation: A(18)=1!+ 8! =40321 
Note that A(80) and A(81) are also 
40321, But 18 is the smallest 
number.
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
void storeFactorials(vector<int> &factorial) {
    factorial[0] = 1;
    for(int i=1; i<=9; i++) {
        factorial[i] = factorial[i-1]*i;
    }
}

vector<int> FactDigit(int N) {
	// First I need to store factorial of numbers from 1 to 9
    vector<int> factorial(10);
    storeFactorials(factorial);
    
    vector<int> res;
    
    for(int i=9; i>0; i--) {
        int val = factorial[i];
        int rep = N/val;
        N -= rep*val;
        while(rep--) {
	        res.push_back(i);
        }
    }
    
    reverse(res.begin(), res.end());
    return res;
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.FactDigit(N);
		for(auto i: ans)
			cout << i;
		cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends