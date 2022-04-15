#include <stdio.h>
int searchh(int arr[],int size,int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element)
        {
            return i;
        }       
    }
    return -1;    
}

int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    // Keep searching until low <= high
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    } 
    return -1;  
}

int main(){
    while (1)
    {
        int input;
        printf("1)Linear 2)Binary Search [1/2] : ");
        scanf("%d",&input);
        if (input == 1)
        {
            int element;
            printf("Enter A number : ");
            scanf("%d",&element);
            int arr[] = {1,2,6,9,8,4,6,42,646,5,64};
            int size = sizeof(arr)/sizeof(int);
            int ser = searchh(arr,size,element);
            printf("The Element %d is found at index %d\n", element, ser);
        }
        else
        {
            int element;
            printf("Enter A number : ");
            scanf("%d",&element);
            int arr[] = {1,2,6,9,8,4,6,42,646,5,64};
            int size = sizeof(arr)/sizeof(int);
            int ser = binarySearch(arr,size,element);
            printf("The Element %d is found at index %d\n", element, ser);
        }
    }
    return 0;
}