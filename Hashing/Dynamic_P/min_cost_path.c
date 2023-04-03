/*
Given a cost matrix cost[][] and a position (M, N) in cost[][], 
write a function that returns cost of minimum cost path to reach (M, N)
from (0, 0). Each cell of the matrix represents a cost to 
traverse through that cell. The total cost of a path to reach 
(M, N) is the sum of all the costs on that path 
(including both source and destination).
You can only traverse down, right and diagonally lower cells
from a given cell, i.e., from a given cell (i, j), cells 
(i+1, j), (i, j+1), and (i+1, j+1) can be traversed. */

#include <stdio.h>
#include <stdlib.h>
#define R 3
#define C 3 

int min(int x,int y,int z);

int mincost(int cost[R][C],int m,int n){
    int i, j;
    int tc[R][C];
 
    tc[0][0] = cost[0][0];
 
    /* Initialize first column of total cost(tc) array */
    for (i = 1; i <= m; i++)
        tc[i][0] = tc[i - 1][0] + cost[i][0];
 
    /* Initialize first row of tc array */
    for (j = 1; j <= n; j++)
        tc[0][j] = tc[0][j - 1] + cost[0][j];
 
    /* Construct rest of the tc array */
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            tc[i][j] = min(tc[i - 1][j - 1], tc[i - 1][j],
                           tc[i][j - 1])
                       + cost[i][j];
 
    return tc[m][n];
}
int min(int x, int y, int z)
{
    if (x < y)
        return (x < z) ? x : z;
    else
        return (y < z) ? y : z;
}



int main(int argc, char const *argv[]){
    int cost[R][C] = { { 1, 2, 3 }, { 4, 8, 2 }, { 1, 5, 3 } };
    printf("%d",mincost(cost,2,2));

    return 0;
}
