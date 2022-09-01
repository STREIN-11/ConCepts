#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
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

void search(struct Node* head, int x)
{
    struct Node* current = head;  // Initialize current
    while (current != NULL)
    {
        if (current->data == x)
            printf("FOUND");
        current = current->next;
    }
}

int main(int argc, char const *argv[]){
    struct Node* head = NULL;
    for (int i = 0; i < 6; i++)
    {
        create(&head,i);
    }
    print(head);
    printf("\n");
    search(head, 21);
    // print(head);
    

    return 0;
}
