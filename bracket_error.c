#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int size;
    int top;
    char *arr;
};
int empty(struct Node *ptr)
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
int full(struct Node *ptr)
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

void push(struct Node *ptr, char val){
    if (full(ptr)){
        printf("Stack si Full");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct Node *ptr)
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

int parenthesisMatch(char * exp){
    struct Node* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
 
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
            push(sp, '(');
        }
        else if(exp[i]==')'){
            if(empty(sp)){
                return 0;
            }
            pop(sp); 
        }
    }
 
    if(empty(sp)){
        return 1;
    }
    else{
        return 0;
    }
    
}



int main(){
    // char n[100],p;
    // printf("Enter exp : ");
    // scanf("%c",&n);
    char * exp = "((8*9)+(7+4)";
    if(parenthesisMatch(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }

    return 0;
}
