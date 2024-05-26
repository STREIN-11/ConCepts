#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

void push(struct Node** head,int data){
    struct Node* neww = (struct Node*)malloc(sizeof(struct Node));
    neww->data = data;
    neww->next = *head;
    neww->prev = NULL;
    if((*head)!=NULL){
        (*head)->prev = neww;
    }
    (*head) = neww;
}

int findSize(struct Node* node)
{
  int res = 0;
  while (node != NULL) {
    res++;
    node = node->next;
  }
  return res;
}

int main(){
    struct Node* head = NULL;
    int size,data;
    printf("Enter Size : ");
    cin>>size;
    printf("Enter Data : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&data);
        push(&head,data);
    }
    cout<<"Size is : "<<findSize(head);

    
}