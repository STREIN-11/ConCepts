/*
Given an array of integers, replace every element with the next 
greatest element (greatest element on the right side) in the array. 
Since there is no element next to the last element, replace it with -1. 
For example, if the array is {16, 17, 4, 3, 5, 2}, then it should 
be modified to {17, 5, 5, 5, 2, -1}. */

#include <bits/stdc++.h>
using namespace std;

void nextGreatest(int arr[], int n){
	for(int i = 0; i<n; i++){
		int max_value = -1;
		for(int j = i+1; j<n; j++){
			max_value = max(max_value, arr[j]);
		}
		arr[i] = max_value;
	}
}

void printArray(int arr[], int size){
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(){
    int n;
    cout<<"Enter Size of Array : ";
    cin>>n;
	int arr[n];
    cout<<"Enter Array Elements : ";
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
	// int size = sizeof(arr)/sizeof(arr[0]);
	nextGreatest (arr, n);
	cout << "The modified array is: \n";
	printArray (arr, n);
	return (0);
}
