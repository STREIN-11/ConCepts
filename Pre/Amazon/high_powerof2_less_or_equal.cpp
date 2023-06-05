/*
Given a number n, find the highest power of 2 that is smaller than 
or equal to n.

Input : n = 10
Output : 8

Input : n = 19
Output : 16

Input : n = 32
Output : 32*/

// C++ program to find highest power of 2 smaller
// than or equal to n.
#include <bits/stdc++.h>
using namespace std;

int highestPowerof2(int n){
	int res = 0;
	for (int i = n; i >= 1; i--) {
		if ((i & (i - 1)) == 0) {
			res = i;
			break;
		}
	}
	return res;
}

int main(){
	int n = 10;
	cout << highestPowerof2(n);
	return 0;
}
