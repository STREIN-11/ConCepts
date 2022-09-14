#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
typedef struct Node
{
    int data;
    struct Node* next;
}Node;

void create(Node** head,int data){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = *head;
    *head = new;
}

void print(Node* head){
    while (head!=NULL)
    {
        printf("%d->",head->data);
        head = head->next;
    }
    printf("Null");
}

int issort(Node* heada,Node* headb,Node* headc,int data){
    Node* a = heada;

    while (a!=NULL)
    {
        Node* b = headb;
        Node* c = headc;
        while (b != NULL && c != NULL){
            int sum = a->data + b->data + c->data;
            if (sum == data)
            {
                printf("Triplet is : %d,%d,%d",a->data,b->data,c->data);
                return 1;
            }
            else if (sum < data)
                b = b->next;
            else
                c = c->next;     
        }
        a = a->next;
    }
    printf("No such Triplet");
    return 0;
    
}

int main(int argc, char const *argv[]){
    struct Node* headA = NULL;
    struct Node* headB = NULL;
    struct Node* headC = NULL;
 
    /*create a linked list 'a' 10->15->5->20 */
    create (&headA, 20);
    create (&headA, 4);
    create (&headA, 15);
    create (&headA, 10);
 
    /*create a sorted linked list 'b' 2->4->9->10 */
    create (&headB, 10);
    create (&headB, 9);
    create (&headB, 4);
    create (&headB, 2);
 
    /*create another sorted linked list 'c' 8->4->2->1 */
    create (&headC, 1);
    create (&headC, 2);
    create (&headC, 4);
    create (&headC, 8);
 
    int givenNumber = 25;
 
    issort (headA, headB, headC, givenNumber);

    return 0;
}
