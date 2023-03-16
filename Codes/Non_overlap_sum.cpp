/*Input : A[] = {1, 5, 3, 8}
        B[] = {5, 4, 6, 7}
Output : 29
1 + 3 + 4 + 6 + 7 + 8 = 29

Input : A[] = {1, 5, 3, 8}
        B[] = {5, 1, 8, 3}
Output : 0
All elements are common.
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Brute Force Method: One simple approach is that for each element in A[] check whether it is present in B[], if it is present in then add it to the result. Similarly, traverse B[] and for every element that is not present in B, add it to result. 
Time Complexity: O(n2).
Auxiliary Space: O(1), As constant extra space is used.

Hashing concept: Create an empty hash and insert elements of both arrays into it. Now traverse hash table and add all those elements whose count is 1. (As per the question, both arrays individually have distinct elements)

Below is the implementation of the above approach:
*/
// CPP program to find Non-overlapping sum
#include <bits/stdc++.h>
using namespace std;
 
 
// function for calculating
// Non-overlapping sum of two array
int findSum(int A[], int B[], int n)
{
    // Insert elements of both arrays
    unordered_map<int, int> hash;   
    for (int i = 0; i < n; i++) {
        hash[A[i]]++;
        hash[B[i]]++;
    }
 
    // calculate non-overlapped sum
    int sum = 0;
    for (auto x: hash)
        if (x.second == 1)
            sum += x.first;
     
    return sum;
}
 
// driver code
int main()
{
    int A[] = { 5, 4, 9, 2, 3 };
    int B[] = { 2, 8, 7, 6, 3 };
     
    // size of array
    int n = sizeof(A) / sizeof(A[0]);
 
    // function call
    cout << findSum(A, B, n);
    return 0;
}
