#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data,degree;
    Node * child,* sibling,* parent;
};
Node* newnode(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->child = temp->sibling = temp->parent = NULL;
    return temp;
}
Node* mergetree(Node* a,Node* b){
    if(a->data > b->data)
        swap(a,b);
    b->parent = a;
    b->sibling = a->child;
    a->child = b;
    a->degree++;
    return a;
}

list<Node*> unionheap(list<Node*> l1,list<Node*>l2){
    list<Node*> _new;
    list<Node*>::iterator ite = l1.begin();
    list<Node*>::iterator ot = l2.begin();

    while (ite!=l1.end() && ot!=l2.end())
    {
        if((*ite)->degree <= (*ot)->degree){
            _new.push_back(*ite);
            ite++;
        }
        else{
            _new.push_back(*ot);
            ot++;
        }
    }

    while (ite!=l1.end()){
        _new.push_back(*ite);
        ite++;
    }
    while(ot!=l2.end()){
        _new.push_back(*ot);
        ot++;
    }
    return _new;
}

list<Node*> adjust(list<Node*> _heap){
    if(_heap.size()<=1)
        return _heap;
    list<Node*> new_heap;
    list<Node*>::iterator it1,it2,it3;
    it1 = it2 = it3 = _heap.begin();

    if(_heap.size()==2){
        it2 = it1;
        it2++;
        it3 = _heap.end();
    }
    else{
        it2++;
        it3 = it2;
        it3++;
    }
    while(it1!=_heap.end()){
        if (it2 == _heap.end())
            it1++;
        else if ((*it1)->degree < (*it2)->degree)
        {
            it1++;
            it2++;
            if(it3!=_heap.end())
                it3++;
        }

        else if (it3 != _heap.end() &&
                 (*it1)->degree == (*it2)->degree &&
                 (*it1)->degree == (*it3)->degree){
            it1++;
            it2++;
            it3++;
        }
        else if ((*it1)->degree == (*it2)->degree){
            Node *temp;
            *it1 = mergetree(*it1, *it2);
            it2 = _heap.erase(it2);
            if (it3 != _heap.end())
                it3++;
        }
    }
    return _heap;
}

list<Node*> inserttree(list<Node*> _heap,Node* tree){
    list<Node*> temp;
    temp.push_back(tree);
    temp = unionheap(_heap,temp);
    return adjust(temp);
}

list<Node*> insert(list<Node*> _heap,int data){
    Node* temp = newnode(data);
    return inserttree(_heap,temp);
}

void printTree(Node *h){
    while (h)
    {
        cout << h->data << " ";
        printTree(h->child);
        h = h->sibling;
    }
}

void print(list<Node *> _heap){
    list<Node *>::iterator it = _heap.begin();
    while (it != _heap.end())
    {
        printTree(*it);
        it++;
    }
}

int main(){
    int data,size;
    list<Node*> _heap;
    cout<<"Enter Size : ";
    cin>>size;
    cout<<"Enter Data : ";
    for (int i = 0; i < size; i++)
    {
        cin>>data;
        _heap = insert(_heap,data);
    }
    cout<<"Elements are : ";
    print(_heap);
    


return 0;
}