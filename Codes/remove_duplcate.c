#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void print(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
void push(struct Node **ptr, int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = (*ptr);
    (*ptr) = newnode;
}

void removee(struct Node *ptr)
{
    struct Node *current = ptr;
    struct Node *next;
    while (current->next != NULL){
        if (current->data == current->next->data){
            next = current->next->next;
            free(current->next);
            current->next = next;
        }
        else{
            current = current->next;
        }      
    }
}

int main()
{
    struct Node *top = NULL;
    int n,dataa;
    printf("How many Times : ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Data : ");
        scanf("%d",&dataa);
        push(&top, dataa);
    }
    print(top);
    printf("Removing...\n");
    removee(top);
    printf("After Removing...\n");
    print(top);
    return 0;
}
