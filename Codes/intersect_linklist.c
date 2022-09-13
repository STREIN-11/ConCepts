#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

void create(struct Node** head,int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = *head;
    *head = new;
}

struct Node* Intersect(
    struct Node* a,
    struct Node* b)
{

    if (a == NULL || b == NULL)
        return NULL;

    if (a->data < b->data)
        return Intersect(a->next, b);
 
    if (a->data > b->data)
        return Intersect(a, b->next);

    struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
    temp->data = a->data;

    temp->next = Intersect(a->next, b->next);
    return temp;
}

void print(struct Node* head){
    while (head!=NULL)
    {
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL");
}

int main(int argc, char const *argv[]){
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* p = NULL;
    for (int i = 0; i < 7; i++)
    {
        create(&head1,i);
    }
    for (int i = 4; i < 7; i++)
    {
        create(&head2,i);
    }
    p = Intersect(head1,head2);
    printf("Same is : ");
    print(p);
    
    

    return 0;
}
