#include <stdio.h>
#include <stdlib.h>
void sort(int A[], int size){
    int i, key, j;
    for (i = 1; i < size; i++){
        key = A[i];
        j = i-1;
        while (j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1] = key;
    }
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    int size;
    printf("Enter Array size : ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter Array Elements : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, size);
    printf("After Sorting : ");
    print(arr, size);

    return 0;
}
