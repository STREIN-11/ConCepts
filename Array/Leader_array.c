#include <stdio.h>
#include <stdlib.h>

void cal(int arr[], int size)
{
    int j = 0;
    int ar[size];
    for (int i = 0; i < size; i++)
    {
        ar[i] = arr[i];
    }
    
    for (int i = 0; i < size; i++)
    {
        if (j < arr[i])
        {
            j = arr[i];
            for (int l = j; l < size; l++)
            {
                /* code */
            }
            
        }
    }
    printf("Leader is : %d\n", j);

    for (int i = 0; i < size; i++)
    {
        if (ar[i] == j)
        {
            for (int i=0 ; i < size; i++)
            {
                printf("R : %d",ar[i]);
            }
            
        }
        
    }
    
    
    
}


int main()
{
    int size;
    printf("Enter Size : ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter Array Element : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    cal(arr, size);

    return 0;
}
