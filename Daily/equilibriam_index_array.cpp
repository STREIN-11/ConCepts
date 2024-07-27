#include <bits/stdc++.h>
using namespace std;

int eqil(long long arr[],int n){
    long long leftsum,rightsum;
    for (int i = 0; i < n; i++)
    {
        leftsum = 0;
        for(int j=0; j<i; j++)
            leftsum+=arr[j];
        
        rightsum = 0;
        for(int j = i+1; j<n; j++)
            rightsum+=arr[j];
        if(leftsum==rightsum)
            return i+1;
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter Size : ";
    cin>>n;
    long long arr[n];
    cout<<"Enter Data : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int q = eqil(arr,n);
    cout<<"Output : "<<q;

}