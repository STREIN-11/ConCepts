#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct Stack
{
    char *arr;
    unsigned val;
    int head;
};



struct Stack* create(unsigned val){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->val = val;
    stack->head = -1;
    stack->arr = (char*)malloc(stack->val * sizeof(char));
    return stack;
}

int isFull(struct Stack* stack){
    return stack->head == stack->val-1;
}

int isEmpty(struct Stack* stack){
    return stack->head == -1;
}

void push(struct Stack* stack,char c){
    if (isFull(stack))
        return;
    stack->arr[++stack->head] = c;
    
}

char pop(struct Stack* stack){
    if(isEmpty(stack))
        return '0';
    return stack->arr[stack->head--];
}

void reverse(char arr[]){
    int n = strlen(arr);
    struct Stack* stack = create(n);
    int i;
    for (i = 0; i < n; i++)
        push(stack,arr[i]);

    for (i = 0; i < n; i++)
        arr[i] = pop(stack);
    
}

int main(int argc, char const *argv[]){
    char arr[1000];
    printf("Enter A String : ");
    scanf("%s",&arr);
    reverse(arr);
    printf("Reverse is : %s",arr);

    return 0;
}



