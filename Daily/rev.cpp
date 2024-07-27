#include <bits/stdc++.h>
using namespace std;
void sort(int arr[],int n){
    sort(arr,arr+n,greater<int>());
    for (int i = n-1; i >=0; i--)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(){
    int n;
    cout<<"Enter size : ";
    cin>>n;
    int arr[n];
    cout<<"Enter data : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,n);
}