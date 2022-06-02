#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void print(struct Node* ptr){
    while (ptr != NULL)
    {
        printf("%d->",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
void push(struct Node** ptr,int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = (*ptr);
    (*ptr) = newnode;
}
struct Node* reverse(struct Node* head){
    struct Node * prev = NULL;
    struct Node * curr = head;
    struct Node * next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;   
        prev = curr;
        curr = next;
    }
    head = prev;   
}

void nth(struct Node* ptr,int index){
    struct Node* top = ptr;
    int len = 0;
    while (top != NULL) {
        top = top->next;
        len++;
    }
    if(len<index)
        return;
    top = ptr;
    for (int i = 1; i < len-index+1; i++)
    {
        top = top->next;
    }
    printf("Result is : %d",top->data);
}

int main(){
    struct Node* head = NULL;
    int n,dataa,index;
    printf("How many Times : ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Data : ");
        scanf("%d",&dataa);
        push(&head, dataa);
    }
    print(head);
    printf("Enter Index: ");
    scanf("%d",&index);
    nth(head,index);

    return 0;
}
