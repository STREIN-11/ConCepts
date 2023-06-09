/*
The name of this searching algorithm may be misleading as it works in O(Log n) time. The name comes from the way it searches an element.

Given a sorted array, and an element x to be
searched, find position of x in the array.

Input:  arr[] = {10, 20, 40, 45, 55}
        x = 45
Output: Element found at index 3

Input:  arr[] = {10, 15, 25, 45, 55}
        x = 15
Output: Element found at index 1*/

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int, int, int);

int exponentialSearch(int arr[], int n, int x){
    if (arr[0] == x)
        return 0;

    int i = 1;
    while (i < n && arr[i] <= x)
        i = i * 2;

    return binarySearch(arr, i / 2,
                        min(i, n - 1), x);
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

// Driver code
int main(void){
    int size,key;
    cout<<"Enter Size : ";
    cin>>size;
    int arr[size];
    // int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Enter Data : ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter Key : ";
    cin>>key;
    int result = exponentialSearch(arr, size, key);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}