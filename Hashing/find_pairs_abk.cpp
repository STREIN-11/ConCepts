/*
Input  :  arr[] = {2, 3, 5, 4, 7}   
              k = 3
Output :  (7, 4), (3, 4), (3, 5), (3, 7)
7 % 4 = 3
3 % 4 = 3
3 % 5 = 3
3 % 7 = 3*/

// C++ implementation to find such pairs
#include <bits/stdc++.h>
using namespace std;

// Function to find pair such that (a % b = k)
bool printPairs(int arr[], int n, int k)
{
	bool isPairFound = true;

	// Consider each and every pair
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// Print if their modulo equals to k
			if (i != j && arr[i] % arr[j] == k) {
				cout << "(" << arr[i] << ", "
					<< arr[j] << ")"
					<< " ";
				isPairFound = true;
			}
		}
	}

	return isPairFound;
}

// Driver program
int main()
{
	int arr[] = { 2, 3, 5, 4, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;

	if (printPairs(arr, n, k) == false)
		cout << "No such pair exists";

	return 0;
}
