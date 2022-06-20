#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void print(struct Node *head)
{
    printf("LinkedList: ");
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node *push(struct Node *head, int data)
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

void get_node(struct Node *head, int value)
{
    int c = 1;
    struct Node *curr = head;
    while (curr != NULL)
    {
        if (c == value){
            printf("Data is: %d\n", curr->data);
            break;
        }
        else{
            c++;
        }
        curr = curr->next;
    }
}

int main()
{
    int n, dataa, value;
    printf("How many Times : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Data : ");
        scanf("%d", &dataa);
        head = push(head, dataa);
    }
    printf("Enter Value : ");
    scanf("%d", &value);
    print(head);
    head = reverse(head);
    get_node(head, value);

    return 0;
}
