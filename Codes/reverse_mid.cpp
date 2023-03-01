#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;

Node* create(Node* head,int data){
    struct Node* neww = (struct Node*)malloc(sizeof(struct Node));
    neww->data = data;
    neww->next = head;
    head = neww;
    return head;
}

void print(struct Node* head){
    printf("Data : ");
    while (head != NULL)
    {
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL");    
}

struct Node* reverse(Node* head,int k){
     Node* l1=head;
        int count=0;
        while(l1){
            count++;
            l1=l1->next;
        }
        Node* l2=head;
        Node* prev1=NULL;
        for(int i=0;i<k;i++){
            Node* next1=l2->next;
            l2->next=prev1;
            prev1=l2;
            l2=next1;
        }
        Node* prev2=NULL;
        for(int i=k;i<count;i++){
            Node* next2=l2->next;
            l2->next=prev2;
            prev2=l2;
            l2=next2;
        }
       Node* ans=prev1;
       while(ans->next){
           ans=ans->next;
       }
       ans->next=prev2;
       return prev1;
}

int main(){
    int l,data,data2;
    cout<<"Enter the Size : ";
    cin>>l;
    cout<<"Enter Data : ";
    for (int i = 0; i < l; i++)
    {
        cin>>data;
        head = create(head,data);
    }
    print(head);
    cout<<"\nEnter reverse length : ";
    cin>>data2;
    head = reverse(head,data2);
    print(head);
    
return 0;
}