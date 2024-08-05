/*
Input: N = 4, A = {10, 10, 10, 10}, K = 2 
Output : 20
Explanation: Here we can divide the boards into 2 equal sized partitions (Painter 1 will paint boards A1 and A2, and Painter 2 will paint boards A3 and A4). So each painter gets 20 units of board and the total time taken is 20. 
Input: N = 4, A = {10, 20, 30, 40}, K = 2 
Output : 60
Explanation: Since there are only 2 painters, therefore divide first 3 boards to painter 1 (A1, A2 and A3) 
with time = 60, and last board to painter 2 (A4) with time = 40. Therefore total time taken = 60, which is 
the minimum possible.
Please note the combination A1 and A4 to Painter 1 with time 50, and A2 and A3 to Painter 2 with time 50, 
will yield a smaller time (50 units). But this cant be considered due to the constraint that a painter cannot 
paint non-continuos series of boards.
*/
#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int from, int to)
{
	int total = 0;
	for (int i = from; i <= to; i++)
		total += arr[i];
	return total;
}

int partition(int arr[], int n, int k){
	if (k == 1)
		return sum(arr, 0, n - 1);
	if (n == 1) 
		return arr[0];

	int best = INT_MAX;

	for (int i = 1; i <= n; i++)
		best = min(best, max(partition(arr, i, k - 1),
							sum(arr, i, n - 1)));

	return best;
}

int main(){
	int arr[] = { 10, 20, 60, 50, 30, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	cout << partition(arr, n, k) << endl;

	return 0;
}
