/*
    Input: arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3} 
    Output: 2 
    In the given array all element appear three times except 2 which appears once.

    Input: arr[] = {10, 20, 10, 30, 10, 30, 30} 
    Output: 20 
    In the given array all element appear three times except 20 which appears once. 
*/

#include <bits/stdc++.h>
using namespace std;

int element(int arr[],int n){
    int ones=0,twos =0;
    int bit;
    for (int i = 0; i < n; i++)
    {
        twos = twos|(ones&arr[i]);
        ones = ones^arr[i];
        bit = ~(ones&twos);
        ones &= bit;
        twos &= bit;
    }
    return ones;
}

int main(){
    int n;
    cout<<"Enter Size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter Data: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Single Element is : "<<element(arr,n);
}