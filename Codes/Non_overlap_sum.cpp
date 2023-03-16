SA
Array
Matrix
Strings
Hashing
Linked List
Stack
Queue
Binary Tree
Binary Search Tree
Heap
Graph
Searching
Sorting
Divide & Conquer
Mathematical
Geometric
Bitwise
Greedy
Backtracking
Branch and Bound
Dynamic Programming
Pattern Searching
Randomized

▲
Related Articles
Write an Article
Write an Interview Experience
Hashing Data Structure
Introduction to Hashing – Data Structure and Algorithm Tutorials
What is Hashing?
Index Mapping (or Trivial Hashing) with negatives allowed
Separate Chaining Collision Handling Technique in Hashing
Open Addressing Collision Handling technique in Hashing
Double Hashing
Load Factor and Rehashing
Easy problems on Hashing
Find whether an array is subset of another array
Union and Intersection of two Linked List using Hashing
Check if pair with given Sum exists in Array
Maximum distance between two occurrences of same element in array
Most frequent element in an array
Find the only repetitive element between 1 to N-1
How to check if two given sets are disjoint?
Non-overlapping sum of two sets
Check if two arrays are equal or not
Find missing elements of a range
Minimum number of subsets with distinct elements
Remove minimum number of elements such that no common element exist in both array
Count pairs with given sum
Count quadruples from four sorted arrays whose sum is equal to a given value x
Sort elements by frequency | Set 4 (Efficient approach using hash)
Find all pairs (a, b) in an array such that a % b = k
Group words with same set of characters
k-th distinct (or non-repeating) element among unique elements in an array.
Intermediate problems on Hashing
Hard problems on Hashing
Non-overlapping sum of two sets

Difficulty Level : Basic
Last Updated : 20 Jan, 2023
Read
Discuss
Courses
Practice
Video
Given two arrays A[] and B[] of size n. It is given that both array individually contains distinct elements. We need to find the sum of all elements that are not common.

Examples: 

Input : A[] = {1, 5, 3, 8}
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

C++
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
