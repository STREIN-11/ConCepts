#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// struct Node* head = NULL;

void push(struct Node **head, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = (*head);
    (*head) = temp;
}

void print(struct Node *head)
{
    printf("Link List : ");
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL");
}

struct Node *delete1st(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// case 2: delete btwn nodes
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// case 3: delete at the end
struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// case 4: delete at value
struct Node *deleteAtValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

int main(){
    struct Node *head = NULL;
    while (1)
    {
        int size, data, value, sack, choice,ch,pos;
        printf("1)Push{}, 2)print{} 3)Delete{} : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter data : ");
            scanf("%d", &data);
            push(&head, data);
        }
        else if (choice == 2)
        {
            print(head);
            printf("\n");
        }
        else if (choice == 3)
        {
            printf("1)Delete 1st, 2)DeleteEND, 3)Delete Index : ");
            scanf("%d",&ch);
            if (ch == 1)
            {
                head = delete1st(head);   
            }
            else if (ch == 2)
            {
                head = deleteAtEnd(head);
            }
            else if (ch == 3)
            {
                printf("Enter position : ");
                scanf("%d",&pos);
                head = deleteAtValue(head,pos);
            }    
            else
            {
                printf("Invalid Choice");
            }
            
        }
        else
        {
            printf("Invalid Choice");
        }
        
    }
    // scanf("%d",&value);
    // delete(&head,value);
    return 0;
}