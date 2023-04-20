/*
Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True  
There is a subset (4, 5) with sum 9.












Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
There is no subset that add up to 30.*/

#include<bits/stdc++.h>
using namespace std;
int tab[2000][2000];

int subsetSum(int *a,int n,int sum){
    if (sum == 0)
        return 1;
         
    if (n <= 0)
        return 0;

    if (tab[n - 1][sum] != -1)
        return tab[n - 1][sum];

    if (a[n - 1] > sum)
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum);
    else{
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum) ||
                       subsetSum(a, n - 1, sum - a[n - 1]);
    }

}

int main(){
    // Storing the value -1 to the matrix
    memset(tab, -1, sizeof(tab));
    int size,sum;
    cout<<"Enter Size : ";
    cin>>size;
    int arr[size];
    cout<<"Enter Array Elements : ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    printf("Enter Sum : ");
    cin>>sum;
    if(subsetSum(arr,size,sum)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    
return 0;
}
