/*
Maximum size square sub-matrix with all 1s
https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
https://www.youtube.com/watch?v=vI4PE4JdadE*/

#include<bits/stdc++.h>
using namespace std;
#define R 6
#define C 5

void print(bool M[R][C]){
    int S[2][C], Max = 0;
 
    // set all elements of S to 0 first
    memset(S, 0, sizeof(S));
 
    // Construct the entries
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
 
            // Compute the entry at the current position
            int Entrie = M[i][j];
            if (Entrie)
                if (j)
                    Entrie
                        = 1
                          + min(S[1][j - 1],
                                min(S[0][j - 1], S[1][j]));
 
            // Save the last entry and add the new one
            S[0][j] = S[1][j];
            S[1][j] = Entrie;
 
            // Keep track of the max square length
            Max = max(Max, Entrie);
        }
 
    // Print the square
    cout << "Maximum size sub-matrix is: \n";
    for (int i = 0; i < Max; i++, cout << '\n')
        for (int j = 0; j < Max; j++)
            cout << "1 ";
}

int main(){
    bool M[R][C] = { { 0, 1, 1, 0, 1 }, { 1, 1, 0, 1, 0 },
                     { 0, 1, 1, 1, 0 }, { 1, 1, 1, 1, 0 },
                     { 1, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0 } };
    print(M);


return 0;
}