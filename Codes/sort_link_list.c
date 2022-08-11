#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Data;
    struct Node *next;
};

struct Node *head = NULL;

void print(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->Data);
        head = head->next;
    }
    printf("NULL");
}

struct Node *push(struct Node *head, int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->Data = data;
    new->next = head;
    head = new;
}

void swap(struct Node *a, struct Node *b) 
{ 
    int temp = a->Data; 
    a->Data = b->Data; 
    b->Data = temp; 
} 

void bubbleSort(struct Node *head) 
{ 
    int swapped, i; 
    struct Node *ptr1; 
    struct Node *ptr2 = NULL; 

    if (head == NULL) 
        return; 
    do
    { 
        swapped = 0; 
        ptr1 = head; 
  
        while (ptr1->next != ptr2) 
        { 
            if (ptr1->Data > ptr1->next->Data) 
            { 
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        ptr2 = ptr1; 
    } 
    while (swapped); 
}


int main()
{
    int size, data, height;
    printf("Enter Height : ");
    scanf("%d", &height);
    for (int i = 0; i < height; i++)
    {
        printf("Enter Size : ");
        scanf("%d", &size);
        for (int i = 0; i < size; i++)
        {
            printf("Enter Data : ");
            scanf("%d", &data);
            head = push(head,data);
        }
    }
    print(head);
    printf("After Sorting : \n");
    bubbleSort(head);
    print(head);
    return 0;
}
