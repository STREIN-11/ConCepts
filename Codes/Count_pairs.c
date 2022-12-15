#include <stdio.h>
#include <stdlib.h>





void sort(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void cal(int *arr, int n, int size)
{
    int i, j, k = 0,l=0;
    for (i = 0; i < size; i++)
    {
        //loop
        for (j = 0; j < size; j++)
        {
            if (i == j)
            {
                l++;
            }
            else
            {
                int t = arr[i] + arr[j];
                if (t % n == 0)
                {
                    k++;
                }
                else
                    printf("y\n");
            }
        }
    }
    printf("R : %d", k);
}

int main()
{
    int size, n;
    printf("Enter Array Size : ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter Array Element : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter Number : ");
    scanf("%d", &n);
    sort(arr, size);
    cal(arr, n, size);

    return 0;
}
