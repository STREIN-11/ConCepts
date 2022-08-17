#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    unsigned char;
    struct stack* next;
};


int main(int argc, char const *argv[])
{
    char arr[100];
    printf("Enter Character : ");
    scanf("%s", &arr);

    printf("%s", arr);

    return 0;
}
