#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;
struct Node* push(struct Node* head, int data)
{
    struct Node* new= (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = head;
    new->prev = NULL;
    if (head != NULL)
        head->prev = new;
    head = new;
}

void print(struct Node* head)
{
    struct Node* last;
    printf("\nData :  ");
    while (head != NULL) {
        printf("%d->", head->data);
        last = head;
        head = head->next;
    }
    printf("NULL");
 
    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf("%d->", last->data);
        last = last->prev;
    }
    printf("NULL");
}




int main(int argc, char const *argv[]){
    for (int i = 0; i < 6; i++)
    {
        head = push(head,i);
    }
    print(head);
    

    return 0;
}
