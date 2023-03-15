#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head,int data){
    struct Node* new_data = (struct Node*)malloc(sizeof(struct Node));
    new_data->data = data;
    new_data->next = *head;
    *head = new_data;
}

struct Node* get_interset(Node* head1,Node* head2){
    unordered_map<int, bool> m;
    struct Node* result = NULL;
    Node* p = head1;
    while(p!= NULL){
        m[p->data] = true;
        p = p->next;
    }
    p = head2;
    while (p!=NULL){
        if(m[p->data]==true){
            push(&result,p->data);
        }
        p = p->next;
    }
    return result;
}

struct Node* getunion(Node* head1,Node* head2){
    set<int> union_list;
    Node* p = head1;
    while(p!=NULL){
        union_list.insert(p->data);
        p = p->next;
    }
    p=head2;
    while(p!=NULL){
        union_list.insert(p->data);
        p = p->next;
    }
    Node* result = NULL;
    for(auto i:union_list){
        push(&result,i);
    }
    return result;
}

void printlist(struct Node* node){
    while(node!=NULL){
        printf("%d",node->data);
        node = node->next;
    }
}

void printunion(Node* head1, Node* head2){
    Node* intersection_list = get_interset(head1,head2);
    Node* union_list = getunion(head1,head2);

    printf("Intersection List is : ");
    printlist(intersection_list);
    printf("\nUnion List is : ");
    printlist(union_list);
}

int main(){
    struct Node* head1 = NULL;
    struct Node* head2 = NULL; 
    int data1,data2,size1,size2;

    cout<<"Enter 1st length : ";
    cin>>size1;
    cout<<"Enter Data : ";
    for (int i = 0; i < size1; i++)
    {
        cin>>data1;
        push(&head1,data1);
    }
    
    cout<<"Enter 2nd Length : ";
    cin>>size2;
    cout<<"Enter Data : ";
    for (int i = 0; i < size2; i++)
    {
        cin>>data2;
        push(&head2,data2);
    }

    cout<<"First list is : \n";
    printlist(head1);
    cout<<"\nSecond list is : \n";
    printlist(head2);
    cout<<"\n";
    printunion(head1,head2);
    
return 0;
}