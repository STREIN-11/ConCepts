#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void print(struct Node* head){
    printf("Data : ");
    while (head!=NULL)
    {
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL");
}

struct Node* create(struct Node* head,int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = head;
    head = new;
}
void printMiddle(struct Node *head)
{
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;
 
    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
}

int main(int argc, char const *argv[]){
    for (int i = 0; i < 7; i++)
    {
        head = create(head,i);
    }
    printMiddle(head);
    print(head);
    

    return 0;
}
