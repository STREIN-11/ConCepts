/*
Input : A[] = { 1, 2, 3, 4}
        B[] = { 2, 3, 4, 5, 8 }
Output : 3
We need to remove 2, 3 and 4 from any array.

Input : A[] = { 4, 2, 4, 4}
        B[] = { 4, 3 }
Output : 1
We need to remove 4 from B[]

Input : A[] = { 1, 2, 3, 4 }
        B[] = { 5, 6, 7 }
Output : 0
There is no common element in both.*/

#include<bits/stdc++.h>
using namespace std;

int remove(int arr[],int ar[],int n,int m){
    unordered_map<int,int>countA, countB;
    for (int i = 0; i < n; i++){
        countA[arr[i]]++;
    }
    for(int i=0; i<m; i++){
        countB[ar[i]]++;
    }
    int res = 0; 
    for(auto x:countA )
        if(countB.find(x.first)!=countB.end())
            res += min(x.second, countB[x.first]);
    return res;
}
int main(){
    int size1,size2;
    cout<<"Enter Size : ";
    cin>>size1;
    cout<<"Enter 2nd Size : ";
    cin>>size2;
    int arr[size1],ar[size2];
    cout<<"Enter 1st Data : ";
    for (int i = 0; i < size1; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter 2nd Data : ";
    for (int i = 0; i < size2; i++)
    {
        cin>>ar[i];
    }
    cout<<"Result is : "<<remove(arr,ar,size1,size2);

return 0;
}
