// Input:  arr[] = {90, 15, 10, 7, 12, 2} 
// Output: True
// The given array represents below tree
//        90
//      /    \
//    15      10
//   /  \     /
//  7    12  2 
// The tree follows max-heap property as every
// node is greater than all of its descendants.

// Input:  arr[] = {9, 15, 10, 7, 12, 11} 
// Output: False
// The given array represents below tree
//        9
//      /    \
//    15      10
//   /  \     /
//  7    12  11
// The tree doesn't follows max-heap property 9 is 
// smaller than 15 and 10, and 10 is smaller than 11.

// A Simple Solution is to first check root if it’s greater than all of its descendants. Then check for children of the root. Time complexity of this solution is O(n2)

// An Efficient Solution is to compare root only with its children (not all descendants), if root is greater than its children and the same is true for all nodes,
// then tree is max-heap (This conclusion is based on transitive property of > operator, i.e., if x > y and y > z, then x > z).
// The last internal node is present at index (n-2)/2 assuming that indexing begins with 0.
    
#include<bits/stdc++.h>
using namespace std;
bool check(int *arr,int size){
    for (int i = 0; i <=(size-2)/2; i++)
    {
        if(arr[2*i +1]>arr[i])
            return false;
        if(2*i+2<size && arr[2*i+2]>arr[i])
            return false;
    }
    return true;
}

int main(){
    int size;
    cout<<"Enter Size : ";
    cin>>size;
    int arr[size];
    cout<<"Enter Array Elements : ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    check(arr,size)?
        printf("Array is BinaryHeap"):printf("Array is not a BinaryHeap");
return 0;
}
