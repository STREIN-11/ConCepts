/*
Input : X = "GeeksforGeeks", Y = "GeeksQuiz"
Output : 5
The longest common substring is "Geeks" and is of
length 5.

Input : X = "abcdxyz", Y = "xyzabcd"
Output : 4
The longest common substring is "abcd" and is of
length 4.*/

// The auxiliary space used by the solution is O(m*n), where m and n are 
// lengths of string X and Y. The space used by solution can be reduced 
// to O(2*n). 
// Suppose we are at position mat[i][j]. Now if X[i-1] == Y[j-1], 
// then we add the value of mat[i-1][j-1] to our result. That is we 
// add value from previous row and value for all other rows below the
// previous row are never used. So, at a time we are using only two 
// consecutive rows. This observation can be used to reduce the space 
// required to find length of longest common substring. 
// Instead of creating a matrix of size m*n, we create a matrix of 
// size 2*n. A variable currRow is used to represent that either 
// row 0 or row 1 of this matrix is currently used to find length. 
// Initially row 0 is used as current row for the case when length 
// of string X is zero. At the end of each iteration, current row 
// is made previous row and previous row is made new current row. 

#include<bits/stdc++.h>
using namespace std;

int substring(string s,string g){
    int m = s.length();
    int n = g.length();
    int result = 0;

    int len[2][n];
    int currrow = 0;

    for (int i = 0; i <= m; i++){
        for (int j = 0; j <=n; j++){
            if(i==0||j==0){
                len[currrow][j]=0;
            }
            else if(s[i-1]==g[j-1]){
                len[currrow][j] = len[1-currrow][j-1]+1;
                result = max(result,len[currrow][j]);
            }
            else{
                len[currrow][j]=0;
            }
        }
        currrow = 1-currrow;
    }
    return result;


}

int main(){
    string s,g;
    cout<<"Enter first Word : ";
    cin>>s;
    cout<<"Enter second Word : ";
    cin>>g;
    cout<<"Result is : "<<substring(s,g);

return 0;
}