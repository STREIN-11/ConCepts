#include<bits/stdc++.h>
using namespace std;
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

class minheap{
    int *arr;
    int capacity;
    int size;
public:
    
    minheap(int capacity);
    void minheapify(int );
    int parent(int i){return (i-1)/2;}
    int left(int i){return (2*i +1);}
    int right(int i){return (2*i + 1);}
    int extract();
    void decrease(int i,int new_val);
    
    int getmin(){return arr[0];}

    void deletekey(int i);

    void insertkey(int k);
};

minheap::minheap(int cap){
    size = 0;
    capacity = cap;
    arr = new int[cap];
}

void minheap::insertkey(int k){
    if(size == capacity){
        cout<<"Overflow"<<endl;
    }
    size++;
    int i = size-1;
    arr[i] = k;

    while(i!=0 &&arr[parent(i)] > arr[i]){
        swap(&arr[i],&arr[parent(i)]);
        i = parent(i);
    }
}

void minheap::decrease(int i,int new_val){
    arr[i] = new_val;
    while (i!=0 &&arr[parent(i)] > arr[i]){
        swap(&arr[i],&arr[parent(i)]);
        i = parent(i);
    }  
}

int minheap::extract(){
    if(size<=0)
        return INT_MAX;
    if(size == 1){
        size--;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[size-1];
    size--;
    minheapify(0);
    return root;
}

void minheap::deletekey(int i){
    decrease(i,INT_MIN);
    extract();
}

void minheap::minheapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l<size && arr[l]<arr[i])
        smallest = l;
    if(r<size && arr[r]<arr[smallest])
        smallest = r;
    if(smallest!= i ){
        swap(&arr[i],&arr[smallest]);
        minheapify(smallest);
    }
    
}

int main(){
    minheap h(11);
    h.insertkey(2);
    h.insertkey(3);
    h.insertkey(4);
    h.insertkey(5);
    h.insertkey(6);
    h.insertkey(7);
    h.insertkey(8);
    cout<<h.extract()<<"";
    cout<<h.getmin()<<"";
    h.decrease(2,1);
    cout<<h.getmin()<<" ";

return 0;
}
