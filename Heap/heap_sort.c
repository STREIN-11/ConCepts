#include <stdio.h>
#include <stdlib.h>


void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr,int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && arr[left]>arr[largest])
        largest = left;
    if(right<n && arr[right]>arr[largest])
        largest = right;
    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        heapify(arr, n, largest);
    }
}

void sort(int *arr,int n){
    for (int i = n/2-1; i>=0; i--)
    {
        heapify(arr,n,i);
    }
    for (int i = n-1; i>= 0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void print(int *arr,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }
    
    
}

int main(int argc, char const *argv[]){
    int size;
    printf("Enter Array size : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter Array Elements : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,size);
    printf("After Sorting : ");
    print(arr,size);
    

    return 0;
}
