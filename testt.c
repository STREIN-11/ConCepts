// #include<stdio.h>

// int linearSearch(int arr[], int size, int element){
//     for (int i = 0; i < size; i++)
//     {
//         if(arr[i]==element){
//             return i;
//         }
//     }
//     return -1;
// }

// int binarySearch(int arr[], int size, int element){
//     int low, mid, high;
//     low = 0;
//     high = size-1;
//     // Keep searching until low <= high
//     while(low<=high){
//         mid = (low + high)/2;
//         if(arr[mid] == element){
//             return mid;
//         }
//         if(arr[mid]<element){
//             low = mid+1;
//         }
//         else{
//             high = mid -1;
//         }
//     }
//     return -1;

// }

// int main(){
//     // Unsorted array for linear search
//     // int arr[] = {1,3,5,56,4,3,23,5,4,54634,56,34};
//     // int size = sizeof(arr)/sizeof(int);

//     // Sorted array for binary search
//     int arr[] = {1,3,5,56,64,73,123,225,444};
//     int size = sizeof(arr)/sizeof(int);
//     int element = 444;
//     int searchIndex = binarySearch(arr, size, element);
//     printf("The element %d was found at index %d \n", element, searchIndex);
//     return 0;
// }

// #include <stdio.h>
// #include<stdlib.h>
// int calculate(int arr[], int n){
//     int sum;
//     sum = arr[0] + arr[n-1];
//     return sum;
// }
// int main(){
//     int size;
//     printf("Enter The Size of the Array : ");
//     scanf("%d",&size);
//     int arr[size];
//     printf("Enter Array elements : ");
//     for (int i = 0; i < size; i++)
//     {
//         scanf("%d",&arr[i]);
//     }
//     int s = sizeof(arr)/sizeof(arr[0]);
//     int t = calculate(arr, size);
//     printf("%d",t);

//     return 0;
// }

// #include<stdio.h>

// int main()
// {
//     for(int i=1;i<=14;i++)        // for I
//     {
//         for(int j=1;j<=10;j++)
//             printf(" ");
//         if(i<4||i>11)
//         {
//             for(int j=1;j<=20;j++)
//                 printf("Bal");
//             printf("\n");
//         }
//         else
//         {
//             for(int j=1;j<=7;j++)
//                 printf(" ");
//             for(int j=1;j<=5;j++)
//                 printf("Bal");
//             printf("\n");
//         }
//     }
//     printf("\n\n");        //for gapping
//     for(int i=1;i<=3;i++)    //for love
//     {
//         for(int j=1;j<=4*(3-i);j++)
//         {
//             printf(" ");
//         }
//         for(int j=1;j<=2*i-1;j++)
//             printf("Bal");
//         for(int j=1;j<=(24-8*i);j++)
//             printf(" ");
//         for(int j=1;j<=2*i-1;j++)
//             printf("Bal");
//         printf("\n");
//     }
//     for(int i=1;i<=10;i++)
//     {
//         for(int j=1;j<=2*(i-1);j++)
//             printf(" ");
//         for(int j=1;j<=(11-i);j++)
//             printf("Bal");
//         printf("\n");
//     }
//     printf("\n\n");
//     for(int i=1;i<14;i++)     // for U
//     {
//         for(int j=1;j<=8;j++)
//             printf(" ");
//         if(i<=8)
//         {
//             for(int j=1;j<=5;j++)
//                 printf("Bal");
//             for(int j=1;j<=14;j++)
//                 printf(" ");
//             for(int j=1;j<=5;j++)
//                 printf("Bal");
//             printf("\n");
//         }
//         else if(i>8 && i<12)
//         {
//             for(int j=1;j<=(i-8);j++)
//                 printf(" ");
//             for(int j=1;j<=5;j++)
//                 printf("Bal");
//             for(int j=1;j<=(30-2*i);j++)
//                 printf(" ");
//             for(int j=1;j<=5;j++)
//                 printf("Bal");
//             printf("\n");
//         }
//         else
//         {
//             for(int j=1;j<=(i-8);j++)
//                 printf(" ");
//             for(int j=1;j<=(40-2*i);j++)
//                 printf("Bal");
//             printf("\n");
//         }
        
//     }
//     return 0;
// }

#include <stdio.h>
int main(){
    char a[100];
    scanf("%s",&a);
    printf("Yo : %s",a);

    return 0;
}
