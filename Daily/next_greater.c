#include<stdio.h>

void print(int arr[], int n)
{
	int next, i, j;
	for (i=0; i<n; i++)
	{
		next = -1;
		for (j = i+1; j<n; j++)
		{
			if (arr[i] < arr[j])
			{
				next = arr[j];
				break;
			}
		}
		printf("%d -- %d\n", arr[i], next);
	}
}

int main()
{
    int size;
    printf("Enter Size : ");
    scanf("%d",&size);
	int arr[size];
	// int n = sizeof(arr)/sizeof(arr[0]);
    printf("Enter Element : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    
	print(arr, size);
	return 0;
}
