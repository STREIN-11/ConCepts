#include <stdio.h>
#include <stdlib.h>

void cal(int arr[], int size)
{
    int pos, el;
    printf("Enter new Element : ");
    scanf("%d", &el);
    printf("Enter The Position : ");
    scanf("%d", &pos);

    for (int i = size - 1; i >= pos - 1; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = el;
}

void print(int arr[], int size)
{
    printf("Array : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
}

void new (int arr[], int size, int t)
{
    cal(arr, size);
    for (int i = 0; i < t-1; i++)
    {
        cal(arr, size);
    }
    print(arr, size);
}

int main(int argc, char const *argv[])
{
    int size, t;
    printf("Enter Array Size : ");
    scanf("%d", &size);
    int arr[size + 10];
    printf("Enter Array Elements : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("How many Elements : ");
    scanf("%d", &t);
    if (t == 1)
    {
        cal(arr, size);
        print(arr, size);
    }
    else
    {
        new (arr, size, t);
    }

    return 0;
}
