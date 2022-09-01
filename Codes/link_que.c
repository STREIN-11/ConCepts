#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
// struct Node* head = NULL;
void print(struct Node* head){
    printf("Data : ");
    while (head!=NULL)
    {
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL");
}

void create(struct Node** head,int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = *head;
    *head = new;
}

void append(struct Node** head, int new_data)
{
    struct Node* new = (struct Node*) malloc(sizeof(struct Node));
 
    struct Node *last = *head;
 
    new->data  = new_data;

    new->next = NULL;
 
    if (*head == NULL)
    {
       *head = new;
       return;
    }

    while (last->next != NULL)
        last = last->next;
 
    last->next = new;
    return;
}

int main(int argc, char const *argv[]){
    struct Node* head = NULL;
    append(&head,1);
    create(&head,5);
    append(&head,2);
        
    print(head);
    

    return 0;
}
