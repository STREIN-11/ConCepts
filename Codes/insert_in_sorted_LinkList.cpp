/*
Given a linked list sorted in ascending order and an integer called data, insert data in the linked list such that the list remains sorted.

Example 1:
Input:
LinkedList: 25->36->47->58->69->80
data: 19
Output: 
19 25 36 47 58 69 80
Explanation:
After inserting 19 the sorted linked list will look like the one in the output.

Example 2:
Input:
LinkedList: 50->100
data: 75
Output: 
50 75 100
Explanation:
After inserting 75 the sorted linked list will look like the one in the output.*/

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        if(!head) {
            Node* newNode = new Node (data);
            head=newNode;
            return head;
        }
        else if(head->data >= data){
            int temp=head->data;
            Node* newNode = new Node (temp);
            newNode->next=head->next;
            head->data = data;
            head->next=newNode;
            return head;
        }
        else {
            head->next=sortedInsert(head->next,data);
            return head;
        }
    }
};


//{ Driver Code Starts.
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
        
		int data;
		cin>>data;
		
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 

// } Driver Code Ends
