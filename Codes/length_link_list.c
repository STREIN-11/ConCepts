// Iterative C program to find length or count of nodes in a linked list
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

void print(struct Node* head){
    printf("Link List : ");
    while (head != NULL)
    {
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL"); 
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node =
			(struct Node*) malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

int getCount(struct Node* head)
{
	int count = 0; 
	struct Node* current = head; 
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

int main()
{
	struct Node* head = NULL;

	int size,data;
    printf("Enter Size : ");
    scanf("%d",&size);
    printf("Enter The Data : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&data);
        push(&head, data);
    }
    print(head);
    printf("\n");

	printf("count of nodes is %d", getCount(head));
	return 0;
}
