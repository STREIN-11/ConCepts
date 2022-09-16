#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node*next;
}Node;

void push(Node** head,int data){
    Node* new = (Node*)malloc(sizeof(Node));
    Node* temp = *head;
    new->data = data;
    new->next = *head;

    if (*head!=NULL)
    {
        while (temp->next!=*head)
            temp = temp->next;
        temp->next = new;
        
    }
    else{
        new->next = new;
    }
    *head = new;
}

void print(Node* head){
    Node* q = head;
    if (head!=NULL)
    {
        do
        {
            printf("%d->",q->data);
            q = q->next;
        } while (q!=head);  
    }
    printf("NULL");
    
}

int main(int argc, char const *argv[]){
    struct Node* head = NULL;
    for (int i = 0; i < 7; i++)
    {
        push(&head,i);
    }
    print(head);
    

    return 0;
}
