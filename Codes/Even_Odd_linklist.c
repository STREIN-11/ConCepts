#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}Node;

void create(Node** head,int data){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = *head;
    *head = new;
}

void print(Node* head){
    while (head!=NULL)
    {
        printf("%d->",head->data);
        head = head->next;
    }
    printf("Null");
}

void evenodd(Node** head){
    Node* evenstart = NULL;
    Node* evenend = NULL;
    Node* oddstart = NULL;
    Node* oddend = NULL;
    Node* curr = (*head);

    while (curr!=NULL)
    {
        int val = curr->data;
        if(val%2 == 0){
            if (evenstart == NULL)
            {
                evenstart = curr;
                evenend = evenstart;
            }
            else
            {
                evenend->next = curr;
                evenend = evenend->next;
            }       
        }
        else
        {
            if (oddstart == NULL) {
                oddstart = curr;
                oddend = oddstart;
            }
            //else??
        }
        curr = curr->next;
        
    }
    evenend->next = oddstart;
    oddend->next = NULL;

    *head = evenstart;
    
}

int main(int argc, char const *argv[]){
    struct Node* head = NULL;
    for (int i = 0; i < 9; i++)
    {
        create(&head,i);
    }
    printf("Before : \n");
    print(head);
    evenodd(&head);
    printf("\nAfter : \n");
    print(head);
    return 0;
}
