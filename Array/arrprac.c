#include <stdio.h>
#include <stdlib.h>
struct myArray
{
    int t;
    int u;
    int (*ptr);

};
void create(struct myArray *a, int x, int b){
    a->t = x;
    a->u = b;
    a->ptr = (int *)malloc(x*sizeof(int));

}
void show(struct myArray *a){
    for (int i = 0; i < a->u; i++)
    {
        printf("%d",(a->ptr)[i]);
    }
    
}
void setVal(struct myArray *a){
    int n;
    for (int i = 0; i < a->u; i++)
    {
        printf("Enter Your Number :");
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
    
}

int main(void){
    struct myArray mark;
    create(&mark, 10, 2);
    setVal(&mark);
    show(&mark);
    

    return 0;
}
