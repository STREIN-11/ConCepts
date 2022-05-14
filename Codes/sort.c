#include <stdio.h>
#include <stdlib.h>
//Bubble Sorting {
void sorting(int *arr, int size){
    int temp,sorted = 0;
    for (int i = 0; i < size-1; i++)
    {
        // if(i==size-2){
        //     printf("Number of Time Take : %d\n",i+1);
        // }
        printf("Number of Time Take : %d\n",i+1);
        sorted = 1;
        for (int j = 0; j < size-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                sorted = 0;
            }
        } 
        if (sorted){
            return;
        }      
    } 
}

//Insertion Sort
void insersort(int *arr, int size){
    int j,temp;
    for (int i = 1; i <=size-1; i++){
        temp = arr[i];
        j = i-1;
        while (j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;   
    }
}

// Selection Sortt
void selsort(int *arr, int size){
}

int print(int *arr,int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

int main(){
    int size;
    printf("Enter Array Size : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter Array Element : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    insersort(arr,size);
    print(arr,size);
    

    return 0;
}
