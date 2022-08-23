#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

// struct Node* head = NULL;

void push(struct Node** head,int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = (*head);
    (*head) = temp;
}

void print(struct Node* head){
    printf("Link List : ");
    while (head != NULL)
    {
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL");
    
}

void delete(struct Node **head,int value){
    struct Node* temp = *head, *prev;
    while (temp != NULL && temp->data==value)
    {
        (*head) = temp->next;
        free(temp);
        return;
    }
    
    while (temp != NULL && temp->data!=value)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);

}


int main(int argc, char const *argv[]){
    struct Node* head = NULL;
    int size,data,value,sack;
    printf("Enter Size : ");
    scanf("%d",&size);
    printf("Enter The Data : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&data);
        push(&head, data);
    }
    print(head);
    printf("\n");
    printf("How many data want to delete : ");
    scanf("%d",&sack);
    printf("Enter The value Want to delete : ");
    for (int i = 0; i < sack; i++)
    {
        scanf("%d",&value);
        delete(&head,value);
    }
    // scanf("%d",&value);
    // delete(&head,value);
    print(head);
    
    return 0;
}
