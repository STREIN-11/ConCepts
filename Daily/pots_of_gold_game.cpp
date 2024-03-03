// Two players X and Y are playing a game in which there are pots of gold arranged in a line, each containing some gold coins. They get alternating 
// turns in which the player can pick a pot from one of the ends of the line. The winner is the player who has a higher number of coins at the end. 
// The objective is to maximize the number of coins collected by X, assuming Y also plays optimally.
// Return the maximum coins X could get while playing the game. Initially, X starts the game.

// N = 4
// Q[] = {8, 15, 3, 7}
// Output: 22
// Explanation: Player X starts and picks 7. Player Y 
// picks the pot containing 8. Player X picks the pot
// containing 15. Player Y picks 3.
// Total coins collected by X = 7 + 15 = 22.


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxCoins(vector<int>&A,int n)
    {
	    if(n==0) return 0;
	    if(n==1) return A[0];
	    if(n==2) return max(A[0],A[1]);
	    int dp[n][n] = {-1};
	    
	    for(int gap=0;gap<n;gap++){
	        for(int j=0;j<n-gap;j++){
	            if(gap==0){
	                dp[j][j] = A[j];
	            }else if(gap==1){
	                dp[j][j+gap] = max(A[j],A[j+gap]);
	            }else{
	                dp[j][j+gap] = max(
	      A[j]+min(dp[j+2][j+gap],dp[j+1][j+gap-1]),
	     A[j+gap]+min(dp[j][j+gap-2],dp[j+1][j+gap-1]));
	            }
	        } 
	    }
	    return dp[0][n-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
