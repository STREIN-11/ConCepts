#include <stdio.h>

int sorting(int arr[], int n){
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            if (arr[i] > arr[j]){
                int a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
    for (int i = 0; i < n; ++i){
    // printf("After sorting Result is : %d\n",arr[i]);
    }
}

int plusar(int arr[], int ar[], int cal[], int size,int length,int sum){
    for(int i=0;i< size;i++)
	{
		cal[i]=arr[i];
	}
	
	printf("Sum of arrays:-");	
	for(int i = 0, j = size; j < sum && i < length; i++, j++)
	{
		cal[j] = ar[i];	
	}
}
int finalsort(int sorting, int plusar,int cal[],int sum){
    for (int i = 0; i < sum; i++)
    {
        printf(" %d",cal[i]);
    }  
}

int main(){
    int size,length,sum,j;
    printf("Enter Length for 1st Array : ");
    scanf("%d",&size);
    printf("Enter Length for 2nd Array : ");
    scanf("%d",&length);
    sum = size + length;
    int arr[size],ar[length];
    int cal[sum];
    printf("Enter 1st Array elements : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter 2nd Array elements : ");
    for (int i = 0; i < length; i++)
    {
        scanf("%d",&ar[i]);
    }  
    int p = plusar(arr,ar,cal,size,length,sum);
    int t = sorting(cal,sum);
    finalsort(t,p,cal,sum);
    return 0;
}