/*
Input:  n = 2
Output: Number of ways = 2
Explanation: Let the set be {1, 2}
            { {1}, {2} } 
            { {1, 2} }

Input:  n = 3
Output: Number of ways = 5
Explanation: Let the set be {1, 2, 3}
             { {1}, {2}, {3} }
             { {1}, {2, 3} }
             { {2}, {1, 3} }
             { {3}, {1, 2} }
             { {1, 2, 3} }. */
             
#include<bits/stdc++.h>
using namespace std;

int bellnum(int n){
    int bell[n+1][n+1];
    bell[0][0]=1;
    for(int i=1; i<=n; i++){
        bell[i][0] = bell[i-1][i-1];
        for(int j=1; j<=i; j++)
            bell[i][j] = bell[i-1][j-1] + bell[i][j-1];
    }
    return bell[n][0];
}

int main(){
    int l;
    cout<<"Enter Length :";
    cin>>l;
    for (int i = 0; i <= l; i++)
    {
        cout<<"Bell Number in "<< i <<" is : "<<bellnum(i)<<endl;
    }
return 0;
}


