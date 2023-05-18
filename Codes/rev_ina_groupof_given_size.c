#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* head = NULL;

void print (struct Node* head){
    printf("LinkedList: ");
    while (head != NULL)
    {
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* push (struct Node* head,int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node*));
    new->data = data;
    new->next = head;
    head = new;
}

struct Node *reverse (struct Node *head, int k)
{ 
    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;
    int count = 0;

    while (current != NULL && count < k)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next !=  NULL)
       head->next = reverse(next, k);
    return prev;
}


int main(){
    int n, dataa,value;
    printf("How many Times : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Data : ");
        scanf("%d", &dataa);
        head = push(head, dataa);
    }
    printf("Enter Value : ");
    scanf("%d",&value);
    head = reverse(head,value);
    print(head);

    return 0;
}
