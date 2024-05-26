#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};

void remove_duplicate(struct Node* head){
    struct Node* curr = head;
    struct Node* next_next;

    if(curr==NULL)
        return;
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            next_next = curr->next->next;
            free(curr->next);
            curr->next = next_next;
        }
        else{
            curr = curr->next;
        }  
    }  
}

void push(struct Node** head,int data){
    struct Node* neww = (struct Node*)malloc(sizeof(struct Node));
    neww->data = data;
    neww->next = (*head);
    (*head) = neww;
}

void print(struct Node* head){
    while (head!=NULL)
    {
        cout<<head->data;
        head = head->next;
    }
    
}

int main(){
    struct Node* head = NULL;
    int size,data;
    cout<<"Enter Size : ";
    cin>>size;
    cout<<"Enter Data : ";
    for (int i = 0; i < size; i++)
    {
        cin>>data;
        push(&head,data);
    }
    remove_duplicate(head);
    print(head);
}