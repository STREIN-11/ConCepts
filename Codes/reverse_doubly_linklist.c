#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

void reverse(struct Node** head){
    struct Node* temp = NULL;
    struct Node* curr = (*head);

    while (curr!=NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL)
        *head = temp->prev;
    
}

void push(struct Node** head,int data){
    struct Node* new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->prev = NULL;
    new->next = *head;
    if ((*head)!=NULL)
        (*head)->prev = new;
    *head = new;  
}

void print(struct Node* head){
    printf("Data : ");
    while (head!=NULL){
        printf("%d",head->data);
        head = head->next;
    }   
}

int main(int argc, char const *argv[]){
    struct Node* head = NULL;
    int data,size;
    printf("Enter Size : ");
    scanf("%d",&size);
    printf("Enter Data : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&data);
        push(&head,data);
    }
    print(head);
    reverse(&head);
    printf("\nAfter Reverse : \n");
    print(head);

    return 0;
}
