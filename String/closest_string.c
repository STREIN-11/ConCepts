#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cal(char (*arr)[100], int size, char *ar,char *pr){
    int i,j=0,k=0;
    for (i = 0; i < size; i++)
    {
        if (strcmp(arr[i], ar)==0)
        {
            printf("Found 1st Element : %d\n",i);
            j = i;
            // break;
        }
        if (strcmp(arr[i],pr)==0)
        {
            printf("Found 2nd Element : %d\n",i);
            k = i;
        }    
    }
    if (j==0 && k==0)
    {
        printf("Elements Not Found");
    }
    else{
        printf("Distance is : %d",k-j);
    }   
}

int main()
{
    int size;
    char arr[100][100], ar[100],pr[100];
    printf("Enter Size : ");
    scanf("%d", &size);
    printf("Enter Strings : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%s", arr[i]);
    }
    printf("Enter 1st String : ");
    scanf("%s", ar);
    printf("Enter 2nd String : ");
    scanf("%s", pr);

    cal(arr, size, ar,pr);

    return 0;
}
