/*
Given a linked list of characters and a string S.Return all 
the anagrams of the string present in the given linked list.
In case of overlapping anagrams choose the first anagram from left.

Input: a -> b -> c -> a -> d -> b -> c -> a
S = bac
Output: [a -> b -> c, b -> c -> a]
Explanation: In the given linked list,
there are three anagrams: 
1. a -> b -> c -> a -> d -> b -> c -> a
2. a -> b -> c -> a -> d -> b -> c -> a
3. a -> b -> c -> a -> d -> b -> c -> a
But in 1 and 2, a -> b -> c and b -> c-> a
are ovelapping.So we take a -> b -> c as it
comes first from left.So the output is:
[a->b->c,b->c->a]

Input: a -> b -> d -> c -> a
S = bac
Output: -1 
Explanation: There is no anagrams, so output is -1*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  private:
    void reset(Node* &h1,Node* &h2,map<char,int> &mp){
        while(h1 != h2){
            mp[h1->data]++;
            h1 = h1->next;
        }
    }
public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        set<char> st(s.begin(),s.end());
        map<char,int> mp;
        for(auto ch : s) mp[ch]++;
        vector<Node*> ans;
        Node* h1 = head, *h2 = head;
        while(h2){
            if(mp.count(h2->data)){
                if(!(--mp[h2->data])) mp.erase(h2->data);
                if(!mp.empty()){
                    h2 = h2->next;
                }else{
                    ans.push_back(h1);
                    reset(h1,h2,mp);
                    mp[h1->data]++;
                    h2 = h2->next;
                    h1->next = NULL;
                    h1 = h2;
                }
            }else{
                if(st.count(h2->data)){
                    while(h1->data != h2->data){
                        mp[h1->data]++;
                        h1 = h1->next;
                    }
                }else{
                    reset(h1,h2,mp);   
                }
                h1 = h1->next;
                h2 = h2->next;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cout<<"How many times : ";
    cin >> t;
    while (t--) {
        struct Node *head = inputList();
        string s;
        cout<<"Enter String : ";
        cin >> s;
        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}