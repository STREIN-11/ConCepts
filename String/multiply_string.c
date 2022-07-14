#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cal(char* arr,char* ar){
    int x = atoi(arr);
    int y = atoi(ar);
    printf("Enter result is : %d",x*y);
}

void main(int argc, char const *argv[]){
    char arr[100],ar[100];
    printf("Enter 1st String : ");
    scanf("%s",&arr);
    printf("Enter 2nd String : ");
    scanf("%s",&ar);
    cal(arr,ar);

}
