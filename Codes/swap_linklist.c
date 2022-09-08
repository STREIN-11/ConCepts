#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void print(struct Node* head){
    printf("Data : ");
    while (head!=NULL)
    {
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL");
}

struct Node* create(struct Node* head,int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = head;
    head = new;
}

void swap(struct Node* head,int x,int y){
    if(x==y)
        return;
    struct Node* prevx = NULL;
    struct Node* currx = head;
    while (currx && currx->data !=x)
    {
        prevx = currx;
        currx = currx->next;
    }

    struct Node* prevy = NULL;
    struct Node* curry = head;
    while (curry && curry->data !=y)
    {
        prevy = curry;
        curry = curry->next;
    }
    
    if (prevx != NULL)
        prevx->next = curry;
    else
        head = curry;

    if (prevy != NULL)
        prevy->next = currx;
    else
        head = currx;
    
    struct Node* temp = curry->next;
    curry->next = currx->next;
    currx->next = temp;
}

int main(int argc, char const *argv[]){
    for (int i = 0; i < 6; i++)
    {
        head = create(head,i);
    }
    swap(head,3,4);
    print(head);
    return 0;
}
