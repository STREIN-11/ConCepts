/*
Input:  p[] = {40, 20, 30, 10, 30}  
Output: Optimal parenthesization is  ((A(BC))D)
        Optimal cost of parenthesization is 26000
There are 4 matrices of dimensions 40x20, 20x30, 
30x10 and 10x30. Let the input 4 matrices be A, B, 
C and D.  The minimum number of  multiplications are 
obtained by putting parenthesis in following way
(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30




Input: p[] = {10, 20, 30, 40, 30} 
Output: Optimal parenthesization is (((AB)C)D)
        Optimal cost of parenthesization is 30000
There are 4 matrices of dimensions 10x20, 20x30, 
30x40 and 40x30. Let the input 4 matrices be A, B, 
C and D.  The minimum number of multiplications are 
obtained by putting parenthesis in following way
((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

Input: p[] = {10, 20, 30}  
Output: Optimal parenthesization is (AB)
        Optimal cost of parenthesization is 6000
There are only two matrices of dimensions 10x20 
and 20x30. So there is only one way to multiply 
the matrices, cost of which is 10*20*30*/

#include <bits/stdc++.h>
using namespace std;

void printParenthesis(int i, int j, int n, int* bracket,char& name){
	if (i == j) {
		cout << name++;
		return;
	}

	cout << "(";

	printParenthesis(i, *((bracket + i * n) + j), n,
					bracket, name);

	printParenthesis(*((bracket + i * n) + j) + 1, j, n,
					bracket, name);
	cout << ")";
}

void matrixChainOrder(int p[], int n){
	int m[n][n];
	int bracket[n][n];

	for (int i = 1; i < n; i++)
		m[i][i] = 0;

	for (int L = 2; L < n; L++){
		for (int i = 1; i < n - L + 1; i++){
			int j = i + L - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++){
				int q = m[i][k] + m[k + 1][j]
						+ p[i - 1] * p[k] * p[j];
				if (q < m[i][j]){
					m[i][j] = q;
					bracket[i][j] = k;
				}
			}
		}
	}

	char name = 'A';

	cout << "Optimal Parenthesization is : ";
	printParenthesis(1, n - 1, n, (int*)bracket, name);
	cout << "\nOptimal Cost is : " << m[1][n - 1];
}

int main(){
        int n,data;
        cout<<"Enter Array Size : ";
        cin>>n;
        int arr[n];
        cout<<"Enter Data : ";
        for (int i = 0; i < n; i++)
        {
                cin>>arr[i];
        }
	// int arr[] = { 40, 20, 30, 10, 30 };
	// int n = sizeof(arr) / sizeof(arr[0]);
	matrixChainOrder(arr, n);
	return 0;
}
