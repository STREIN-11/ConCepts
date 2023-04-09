/*
You are given 5 integers - N,A,B,C,D.
Let us say all the integers of length N, having only A or B in their decimal representation are good integers. 
Also, among all the good integers, all those integers whose sum of digits contains either C or D or both are best integers.
Find the number of best integers of length N. Since the number of best integers can be huge, print it modulo 109+7.

Input:
N = 2, A = 1, B = 2, C = 3, D = 5
Output: 
2
Explanation: 
The following are good integers:- 
{ 12 , 22 , 11 , 21 }
And the following are best integers:- 
{ 12, 21 } because sum of digits of 11,22
are 2 and 4, they are not equal to C or D

Input:
N = 1, A = 1, B = 1, C = 2, D = 3
Output: 
0
Explanation: 
The following are good integers: - { 1 }
Since sum of digits is 1 which is not equal to
C or D, therefore, answer is 0.*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(int n,int c,int d) {
        while(n) {
            int r=n%10;
            if(r==c || r==d) {
                return true;
            }
            n/=10;
        }
        return false;
    }
    long long binpow(long long a,long long b,long long mod) {
        long long res=1;
        while(b) {
            if(b&1) {
                res=(res*a)%mod;
            }
            a=(a*a)%mod;
            b>>=1;
        }
        return res;
    }
    int bestNumbers(int N, int A, int B, int C, int D) {
        if(A==B) {
            return check(N*A,C,D);
        } 
        long long mod=1e9+7,ans=0;
        vector<long long> fac(N+1,0);
        fac[0]=1;
        for(long long i=1;i<=N;i++) {
            fac[i]=(fac[i-1]*i)%mod;
        }
        for(int i=0;i<=N;i++) {
            int s=i*A+(N-i)*B;
            if(check(s,C,D)) {
                ans=(ans+(fac[N]*binpow((fac[i]*fac[N-i])%mod,mod-2,mod))%mod)%mod;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int A;
        scanf("%d",&A);
        
        
        int B;
        scanf("%d",&B);
        
        
        int C;
        scanf("%d",&C);
        
        
        int D;
        scanf("%d",&D);
        
        Solution obj;
        int res = obj.bestNumbers(N, A, B, C, D);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends