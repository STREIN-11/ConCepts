#include <stdio.h>
#include <stdlib.h>

void cal(int arr[],int n){
    for(int i=0;i<n-1;i++)
	    {
	        if(arr[i]>arr[i+1])
	          arr[i]=arr[i+1];
	        else
	          arr[i]=-1;
	    }
	    arr[n-1]=-1;

    printf("Result is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }
}

int main(int argc, char const *argv[]){
    int size;
    printf("Enter Size : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter Array Elements : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d",arr[i]);
        printf("\n");
    }
    cal(arr,size);

    return 0;
}

// void swap(int* xp, int* yp)
// {
//     int temp = *xp;
//     *xp = *yp;
//     *yp = temp;
// }
// void sort(int arr[],int n)
// {
//     int i, j;
//     for (i = 0; i < n - 1; i++)
//         for (j = 0; j < n - i - 1; j++)
//             if (arr[j] > arr[j + 1])
//                 swap(&arr[j], &arr[j + 1]);
// }