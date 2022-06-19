// You are given an equation of the form x1+x2+...+xN=K. 
// You need to find the total number of positive integral solutions of this
// equation.
// Input: s = a+b=5
// Output: 4
// Explanation: (4,1) , (1,4) , (2,3) , (3,2)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cal(char *arr){
    int k=0,l,w=0;
    char n = arr[strlen(arr)-1];
    // printf("R : %c\n",n);
    int s;
    s = n-'0';
    // printf("Integer is : %d\n",s);
    if (s == 1)
    {
        printf("%d",w);
    }
    else{
        for (int i = 0; i < s; i++)
        {
            for (int j = 0; j < s; j++)
            {
                if (i+j==s)
                {
                    k++;
                }
                else{
                    l++;
                }
            } 
        }
        printf("Count is : %d",k);
    }    
}

int main(){
    printf("Enter String : ");
    char arr[100];
    for (int i = 0; i < 1; i++)
    {
        scanf("%s",arr);
    }
    cal(arr);
    return 0;
}
