#include <stdio.h>
#include <stdlib.h>

//    *****
//   *****
//  *****
// *****
//*****


int main(){
    int row,colom;
    printf("Enter Row : ");
    scanf("%d",&row);

    int count = colom-1;
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < row-i; j++)
        {
            printf(" ");   
        }
        for (int i = 1; i <= row; i++)
        {
            printf("*");
        }
        printf("\n");     
    }
    return 0;
}
