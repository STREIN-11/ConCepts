#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n, count = 0, l = 0;
    printf("Enter A number : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (i % j == 0)
            {
                count++;
            }
        }
        if (count % 2 == 0)
        {
            l++;
        }
    }
    printf("R : %d", l);

    return 0;
}
