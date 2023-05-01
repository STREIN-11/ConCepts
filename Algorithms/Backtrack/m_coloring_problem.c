/*https://www.geeksforgeeks.org/m-coloring-problem/*/





#include <stdbool.h>
#include <stdio.h>
#define V 4

void printSolution(int color[]);

bool isSafe(bool graph[V][V], int color[]){
	for (int i = 0; i < V; i++)
		for (int j = i + 1; j < V; j++)
			if (graph[i][j] && color[j] == color[i])
				return false;
	return true;
}

bool graphColoring(bool graph[V][V], int m, int i,
				int color[V]){
	// if current index reached end
	if (i == V) {
		// if coloring is safe
		if (isSafe(graph, color)) {
			// Print the solution
			printSolution(color);
			return true;
		}
		return false;
	}

	// Assign each color from 1 to m
	for (int j = 1; j <= m; j++) {
		color[i] = j;

		// Recur of the rest vertices
		if (graphColoring(graph, m, i + 1, color))
			return true;

		color[i] = 0;
	}

	return false;
}

void printSolution(int color[])
{
	printf("Solution Exists:"
		" Following are the assigned colors \n");
	for (int i = 0; i < V; i++)
		printf(" %d ", color[i]);
	printf("\n");
}

int main()
{
	/* Create following graph and
	test whether it is 3 colorable
	(3)---(2)
	| / |
	| / |
	| / |
	(0)---(1)
	*/
	bool graph[V][V] = {
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 },
	};
	int m = 3; // Number of colors

	// Initialize all color values as 0.
	// This initialization is needed
	// correct functioning of isSafe()
	int color[V];
	for (int i = 0; i < V; i++)
		color[i] = 0;

	if (!graphColoring(graph, m, 0, color))
		printf("Solution does not exist");

	return 0;
}
