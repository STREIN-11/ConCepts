#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};
int empty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int full(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(struct stack *ptr, int val)
{
    if (full(ptr))
    {
        printf("Stack is Full, can't push %d to stack", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("%d", val);
    }
}

int pop(struct stack *ptr)
{
    if (empty(ptr))
    {
        printf("Stack is underflow");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    int choice;
    printf("1.Push, 2.PoP : ");
    scanf("%d",&choice);
    if (choice == 1)
    {
        int n, num;
        printf("Enter Stack Size : ");
        scanf("%d", &n);
        printf("Enter Number : ");
        scanf("%d", &num);
        sp->size = n;
        sp->top = -1;
        sp->arr = (int *)malloc(sp->size * sizeof(int));
        push(sp, num);
    }
    else
    {
        pop(sp);
    }
    

    return 0;
}
