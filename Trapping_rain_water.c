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
    for (int i = 0; i < n; ++i){
    // printf("After sorting Result is : %d\n",arr[i]);
    }
}

int calculate(int sorting,int arr[],int n){
    int sum = 0;
    for (int i = 0; i < n-2; i++)
    {
        int j = arr[n-2] - arr[i];
        printf("Missing Boxs are : %d\n",j);
        sum = sum + j;
    }
    printf("Final Result is : %d", sum);

}

int main()
{
    int size;
    printf("Enter Array Size : ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter Array Element : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int s = sizeof(arr) / sizeof(arr[0]);
    // short(arr, arr+s);
    for (int i = 0; i < size; i++)
    {
        // printf("Without Sorting : %d\n", arr[i]);
        // printf(" ");
    }
    int t = sorting(arr,size);
    calculate(t,arr,size);

    return 0;
}
