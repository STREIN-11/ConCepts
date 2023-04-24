/*
Given an array of positive distinct integer denoting the
crossing time of ‘n’ people. These ‘n’ people are standing
at one side of bridge. Bridge can hold at max two people at a time.
When two people cross the bridge, they must move at the slower 
person’s pace. Find the minimum total time in which all persons 
can cross the bridge.







Input:  Crossing Times = {10, 20, 30}
Output: 60
Explanation
1. Firstly person '1' and '2' cross the bridge
   with total time about 20 min(maximum of 10, 20) 
2. Now the person '1' will come back with total 
   time of '10' minutes.
3. Lastly the person '1' and '3' cross the bridge
   with total time about 30 minutes
Hence total time incurred in whole journey will be
20 + 10 + 30 = 60*/

// C++ program to find minimum time required to
// send people on other side of bridge
#include <bits/stdc++.h>
using namespace std;

/* Global dp[2^20][2] array, in dp[i][j]--
'i' denotes mask in which 'set bits' denotes
total people standing at left side of bridge
and 'j' denotes the turn that represent on
which side we have to send people either
from left to right(0) or from right to
left(1) */
int dp[1 << 20][2];

/* Utility function to find total time required
to send people to other side of bridge */
int findMinTime(int leftmask, bool turn, int arr[], int& n)
{

	// If all people has been transferred
	if (!leftmask)
		return 0;

	int& res = dp[leftmask][turn];

	// If we already have solved this subproblem,
	// return the answer.
	if (~res)
		return res;

	// Calculate mask of right side of people
	int rightmask = ((1 << n) - 1) ^ leftmask;

	/* if turn == 1 means currently people are at
	right side, thus we need to transfer
	people to the left side */
	if (turn == 1) {
		int minRow = INT_MAX, person;
		for (int i = 0; i < n; ++i) {

			// Select one people whose time is less
			// among all others present at right
			// side
			if (rightmask & (1 << i)) {
				if (minRow > arr[i]) {
					person = i;
					minRow = arr[i];
				}
			}
		}

		// Add that person to answer and recurse for next
		// turn after initializing that person at left side
		res = arr[person]
			+ findMinTime(leftmask | (1 << person),
							turn ^ 1, arr, n);
	}
	else {

		// __builtin_popcount() is inbuilt gcc function
		// which will count total set bits in 'leftmask'
		if (__builtin_popcount(leftmask) == 1) {
			for (int i = 0; i < n; ++i) {

				// Since one person is present at left
				// side, thus return that person only
				if (leftmask & (1 << i)) {
					res = arr[i];
					break;
				}
			}
		}
		else {

			// try for every pair of people by
			// sending them to right side

			// Initialize the result with maximum value
			res = INT_MAX;
			for (int i = 0; i < n; ++i) {

				// If ith person is not present then
				// skip the rest loop
				if (!(leftmask & (1 << i)))
					continue;

				for (int j = i + 1; j < n; ++j) {
					if (leftmask & (1 << j)) {

						// Find maximum integer(slowest
						// person's time)
						int val = max(arr[i], arr[j]);

						// Recurse for other people after
						// un-setting the ith and jth bit of
						// left-mask
						val += findMinTime(
							leftmask ^ (1 << i) ^ (1 << j),
							turn ^ 1, arr, n);
						// Find minimum answer among
						// all chosen values
						res = min(res, val);
					}
				}
			}
		}
	}
	return res;
}

// Utility function to find minimum time
int findTime(int arr[], int n)
{
	// Find the mask of 'n' peoples
	int mask = (1 << n) - 1;

	// Initialize all entries in dp as -1
	memset(dp, -1, sizeof(dp));

	return findMinTime(mask, 0, arr, n);
}

// Driver program
int main()
{
	int arr[] = { 10, 20, 30 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findTime(arr, n);
	return 0;
}
