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

int count(struct Node* head,int x){
    struct Node* temp = head;
    int c = 0;
    while (temp != NULL)
    {
        if (temp->data == x)
            c++;
        temp = temp->next;
    }
    return c;
    
    
}
int main(int argc, char const *argv[]){
    int size,data,check;
    printf("Enter Size : ");
    scanf("%d",&size);
    printf("Enter Data : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&data);
        head = create(head,data);
    }
    printf("Which value want to check : ");
    scanf("%d",&check);
    printf("Your search Result : %d",count(head,check));
    

    return 0;
}
