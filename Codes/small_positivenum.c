#include <stdio.h>
#include <stdlib.h>

int sorting(int arr[], int n){
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            if (arr[i] > arr[j]){
                int a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
}
int cal(int *arr,int size){
    int aux=0,i;
    for (i = 0; i < size; i++)
    {
        if (arr[i+1]-arr[i]==1)
        {
            continue;
        }
        else
        {
            printf("Re : %d",arr[i+1]-1);
            break;
        }       
    }
}

int main(){
    int size;
    printf("Enter A Number : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter Array Element : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    sorting(arr,size);
    cal(arr,size);
    return 0;
}