#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};


void push(struct Node **head, int data)
{
	struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
	struct Node *temp = *head;
	ptr1->data = data;
	ptr1->next = *head;

	if (*head != NULL)
	{
		while (temp->next != *head)
			temp = temp->next;
		temp->next = ptr1;
	}
	else
		ptr1->next = ptr1; /*For the first node */

	*head = ptr1;
}

void print(struct Node *head)
{
    struct Node* temp = head;
    printf("LinkedList: ");
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head);
    }
}


int main(int argc, char const *argv[])
{
    struct Node *head = NULL;
    int n, dataa, value;
    printf("How many Times : ");
    scanf("%d", &n);
    printf("Enter Data : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dataa);
        push(&head, dataa);
    }
    print(head);

    return 0;
}
