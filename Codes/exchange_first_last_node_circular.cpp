#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
struct Node* addToEmpty(struct Node** head, int data)
{
    if (*head != NULL)
        return *head;

    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
 
    temp->data = data;
    *head = temp;
 
    (*head)->next = (*head);
 
    return *head;
}

struct Node* addBegin(struct Node* head, int data)
{
    if (head == NULL)
        return addToEmpty(&head, data);
 
    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
 
    temp->data = data;
    temp->next = head->next;
    head->next = temp;
 
    return head;
}

void traverse(struct Node* head)
{
    struct Node* p;
 
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    p = head;

    do {
        cout << p->data << " ";
        p = p->next;
 
    } while (p != head);
}

struct Node* exchangeNodes(struct Node* head)
{
    // If list is of length 2
    if (head->next->next == head) {
        head = head->next;
        return head;
    }
 
    // Find pointer to previous of last node
    struct Node* p = head;
    while (p->next->next != head)
        p = p->next;
 
    /* Exchange first and last nodes using
       head and p */
    p->next->next = head->next;
    head->next = p->next;
    p->next = head;
    head = head->next;
 
    return head;
}

int main(){
    struct Node* head = NULL;
    int size,data;
    cout<<"Enter Size : ";
    cin>>size;
    addToEmpty(&head,size);
    cout<<"Enter Data : ";
    for (int i = size-1; i>0; i--){
        cin>>data;
        head = addBegin(head,data);
    }
    cout<<"List Before : ";
    traverse(head);
    cout<<endl;
    cout<<"List After : ";
    head = exchangeNodes(head);
    traverse(head);

    return 0;
}