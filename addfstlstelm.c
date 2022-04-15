#include <stdio.h>
#include<stdlib.h>
int calculate(int arr[], int n){
    int sum;
    sum = arr[0] + arr[n-1];
    return sum;
}
int main(){
    int size;
    printf("Enter The Size of the Array : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter Array elements : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    int s = sizeof(arr)/sizeof(arr[0]);
    int t = calculate(arr, size);
    printf("Your Sum is : %d",t);
    return 0;
}