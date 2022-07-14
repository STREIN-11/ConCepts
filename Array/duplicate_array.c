#include <stdio.h>
#include <conio.h>

int duplicate(int* arr,int size){
    int count=0;
        for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                printf("%d",arr[i]);
                count++;
            }
        }
    }
    if(count==0){
        return -1;
    }
    
}

int main(){
    int size;
    printf("Enter Size : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter Array Elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    int k = duplicate(arr,size);
    printf("%d",k);
    main();

    return 0;
}
