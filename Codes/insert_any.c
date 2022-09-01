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

void insert(struct Node* head,int dataa,int pos,int size)
{
    struct Node* new = (struct Node*) malloc(sizeof(struct Node)); 
    new->data = dataa;
    new->next = NULL;

    if(pos < 0 || pos > size) 
        printf("Invalid position to insert\n"); 
    
    else if(pos == 0){
        new->next = head; 
        head = new;
    }
    else 
    {
        struct Node* temp = head; 
        
        while(--pos)
            temp=temp->next;
        
        new->next= temp->next;
        temp->next = new;
    }
}

int main(int argc, char const *argv[]){
    int size,data,pos,dataa;
    printf("Enter Size : ");
    scanf("%d",&size);
    printf("Enter Data : ");
    for (int i = 0; i <= size; i++)
    {
        scanf("%d",&data);
        head = create(head,data);
    }
    printf("Enter Position : ");
    scanf("%d",&pos);
    printf("Enter new data : ");
    scanf("%d",&dataa);  
    insert(head,dataa,pos,size);
    print(head);
    

    return 0;
}
