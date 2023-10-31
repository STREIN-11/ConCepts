/*Given the chessboard dimensions. Find out the number of ways we can place a black and a white Knight on this chessboard such that 
they cannot attack each other.
Note:
The knights have to be placed on different squares. A knight can move two squares horizontally and one square vertically (L shaped), 
or two squares vertically and one square horizontally (L shaped). The knights attack each other if one can reach the other in one move.






Input:
N = 2, M = 2
Output: 12 
Explanation: There are 12 ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.

Input:
N = 2, M = 3
Output: 26
Explanation: There are 26 ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.*/
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int N, int M)
{
    long long int mod = 1e9+7 ;
    long long int ans = 0 ;
    long long int a1 = 1 , a2 = 2 , a4 =4;
    ans+=(long long)(((N*M) -a1)*(N*M)) ;
    if(N >=2 && M>=3){
        ans-=(long long)((N-a1)*(a4)*(M-a2)) ;
    }
    if(N >=3 && M>=2){
        ans-= (long long)((N-a2)*(a4)*(M-a1)) ;
    }
    return (ans%mod) ;
}
