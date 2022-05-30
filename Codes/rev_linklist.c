#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void print(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct Node* push(struct Node* head,int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = head;
    head = new;
}

struct Node* reverse(struct Node* head){
    struct Node * prev = NULL;
    struct Node * curr = head;
    struct Node * next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;   
        prev = curr;
        curr = next;
    }
    head = prev;
    
}



int main()
{
    // struct Node *head = NULL;
    int n,dataa;
    printf("How many Times : ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Data : ");
        scanf("%d",&dataa);
        head = push(head, dataa);
        // reverse(&head);
    }
    head = reverse(head);
    print(head);

    return 0;
}
