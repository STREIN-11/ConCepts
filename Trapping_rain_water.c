#include <stdio.h>
#include <stdlib.h>

int calculate(int arr[]){

}




int main(){
    int size;
    printf("Enter Array Size : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter Array Element : ");
    for (int i = 0; i <size; i++)
    {
        scanf("%d",&arr[i]);
    }
    int s = sizeof(arr)/sizeof(arr[0]);
    short(arr, arr+s);
    for (int i = 0; i <size; i++)
    {
        printf("%d",arr[i]);
    }
    
    

    return 0;
}
