/*
Given n buckets and infinite number of balls. The maximum capacity of each bucket is given in an array capacity[]. 
Find the number of ways to fill the buckets with balls such that each bucket has atleast 1 ball and all the buckets have distinct number
 of balls in them.Note: Since the answer may be very large, calculate the answer modulo 10^9+7.



 
Input: 
n = 1
capacity = [6]
Output: 6
Explanation: Since there is only one 
bucket. It may hold any number of balls 
ranging from 1 to 6.

Input: 
n = 2 
capacity = [5, 8]
Output: 35
Explanation: If the first bucket has 1
ball in it then the second bucket cant have 1 
ball, so the second bucket has 8-1 = 7 choices.
So the first bucket has 5 choices and for each
choice second bucket has 7 choices.
So total there are 35 ways.*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int totalWays(int n, vector<int> a) {
        sort(a.begin(),a.end());
        long long  m = 1e9 + 7;
        long long ans = 1;
        for(int i =0;i<n;i++){
            ans = (ans*(a[i]-i))%m; 
        }
        return ans%m;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>capacity(n);
		for(int i = 0; i < n; i++)
			cin >> capacity[i];
		Solution ob;
		int ans = ob.totalWays(n, capacity);
		cout << ans << "\n";
	}  
	return 0;
}
