#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

int checkPalindrome(struct Node** left, struct Node* right)
{
    if (right == NULL) {
        return 1;
    }
 
    int result = checkPalindrome(left, right->next) && ((*left)->data == right->data);
    (*left) = (*left)->next;
 
    return result;
}
int checkPalin(struct Node* head) {
    return checkPalindrome(&head, head);
}
 
int main(void)
{
    int size;
    printf("Enter Size: ");
    scanf("%d",&size);
    int keys[size];
    printf("Enter Elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&keys[i]);
    } 
    int n = sizeof(keys) / sizeof(keys[0]);
    struct Node* head = NULL;
    for (int i = n - 1; i >= 0; i--) {
        push(&head, keys[i]);
    }
 
    if (checkPalin(head)) {
        printf("The linked list is a palindrome");
    }
    else {
        printf("The linked list is not a palindrome");
    }
 
    return 0;
}