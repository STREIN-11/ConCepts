/*
Given a N*N board with the Knight placed on the first block of 
an empty board. Moving according to the rules of chess knight 
must visit each square exactly once. Print the order of each 
cell in which they are visited.

Input : 
N = 8
Output:
0  59  38  33  30  17   8  63
37  34  31  60   9  62  29  16
58   1  36  39  32  27  18   7
35  48  41  26  61  10  15  28
42  57   2  49  40  23   6  19
47  50  45  54  25  20  11  14
56  43  52   3  22  13  24   5
51  46  55  44  53   4  21  12*/

// C program for Knight Tour problem
#include <stdio.h>
#define N 8

int solveKTUtil(int x, int y, int movei, int sol[N][N],
				int xMove[], int yMove[]);

int isSafe(int x, int y, int sol[N][N])
{
	return (x >= 0 && x < N && y >= 0 && y < N
			&& sol[x][y] == -1);
}

void printSolution(int sol[N][N])
{
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++)
			printf(" %2d ", sol[x][y]);
		printf("\n");
	}
}

int solveKT(){
	int sol[N][N];

	/* Initialization of solution matrix */
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			sol[x][y] = -1;

	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	// Since the Knight is initially at the first block
	sol[0][0] = 0;

	/* Start from 0,0 and explore all tours using
	solveKTUtil() */
	if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
		printf("Solution does not exist");
		return 0;
	}
	else
		printSolution(sol);

	return 1;
}


int solveKTUtil(int x, int y, int movei, int sol[N][N],
				int xMove[N], int yMove[N])
{
	int k, next_x, next_y;
	if (movei == N * N)
		return 1;

	/* Try all next moves from the current coordinate x, y
	*/
	for (k = 0; k < 8; k++) {
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (isSafe(next_x, next_y, sol)) {
			sol[next_x][next_y] = movei;
			if (solveKTUtil(next_x, next_y, movei + 1, sol,xMove, yMove)== 1)
				return 1;
			else
				sol[next_x][next_y] = -1; // backtracking
		}
	}

	return 0;
}

int main(){	
    solveKT();
	return 0;
}
