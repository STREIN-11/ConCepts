#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* head = NULL;

struct Node* create(struct Node* head,int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = head;
    head = new;
}

void insertAfter(struct Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
      printf("the given previous node cannot be NULL");
    }

    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
 
    new_node->data  = new_data;
 
    new_node->next = prev_node->next;
 
    prev_node->next = new_node;
}

void search(struct Node* head, int x)
{
    struct Node* current = head;
    while (current != NULL)
    {
        if (current->data == x)
            head = current;
        current = current->next;
    }
    // printf("Element Not found");
}

void print(struct Node* head){
    printf("Data : ");
    while (head != NULL)
    {
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL");    
}


int main(int argc, char const *argv[]){
    int size,data,choice,af;
    printf("Enter Size : ");
    scanf("%d",&size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter Your Choice 1.Front, 2.Middle : ");
        scanf("%d",&choice);
        if (choice == 1)
        {
            printf("Enter Data : ");
            scanf("%d",&data);
            head = create(head,data);  
        }
        else
        {
            printf("Enter Data : ");
            scanf("%d",&data);
            printf("After : ");
            scanf("%d",&af);
            search(head,af);
            if (search)
            {
                insertAfter(head, data);
            }
            
            // insertAfter(head->next, data);
        }  
    }
    print(head);
    

    

    return 0;
}
