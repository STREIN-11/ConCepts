/*
    Input: a[] = {-5, 3, 6, 12, 15}, b[] = {-12, -10, -6, -3, 4, 10}
    Output: The median is 3.
    Explanation: The merged array is: ar3[] = {-12, -10, -6, -5 , -3, 3, 4, 6, 10, 12, 15}.
    So the median of the merged array is 3

    Input: a[] = {2, 3, 5, 8}, b[] = {10, 12, 14, 16, 18, 20}
    Output: The median is 11.
    Explanation : The merged array is: ar3[] = {2, 3, 5, 8, 10, 12, 14, 16, 18, 20}
    If the number of the elements are even. So there are two middle elements.
    Take the average between the two: (10 + 12) / 2 = 11.
*/


#include <bits/stdc++.h>
using namespace std;

int Solution(int arr[], int n)
{

    // If length of array is even
    if (n % 2 == 0) {
        int z = n / 2;
        int e = arr[z];
        int q = arr[z - 1];
        int ans = (e + q) / 2;
        return ans;
    }

    // If length if array is odd
    else {
        int z = round(n / 2);
        return arr[z];
    }
}
int main()
{
    int arr1[] = { -5, 3, 6, 12, 15 };
    int arr2[] = { -12, -10, -6, -3, 4, 10 };

    int i = sizeof(arr1) / sizeof(arr1[0]);
    int j = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[i + j];
    int l = i + j;
    // Merge two array into one array
    for (int k = 0; k < i; k++) {
        arr3[k] = arr1[k];
    }

    int a = 0;
    for (int k = i; k < l; k++) {
        arr3[k] = arr2[a++];
    }

    // Sort the merged array
    sort(arr3, arr3 + l);
    cout << "Median = " << Solution(arr3, l);
}

