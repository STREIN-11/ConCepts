#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

struct Node* convert(struct Node* head){
    struct Node* start = head;
    while (head->next != NULL){
        head = head->next;
    }
    head->next = start;
    return start;
    
}

void push(struct Node** head,int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = (*head);
    (*head) = new;
}

void printList(struct Node *head)
{
	struct Node *temp = head;
	if (head != NULL)
	{
		do
		{
			printf("->%d ", temp->data);
			temp = temp->next;
		}
		while (temp != head);
	}
}

int main(){
    struct Node* head=NULL;
    int size,data;
    printf("Enter size : ");
    scanf("%d",&size);
    printf("Enter data : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&data);
        push(&head,data);
    }
    convert(head);
    printf("Result : ");
    printList(head);
}