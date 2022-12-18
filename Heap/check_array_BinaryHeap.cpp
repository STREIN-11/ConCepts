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