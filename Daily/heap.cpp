#include <bits/stdc++.h> 
using namespace std; 

class MaxHeap { 
	int* arr; 
	int maxSize; 
	int heapSize; 

public:
	MaxHeap(int maxSize);  
	void MaxHeapify(int); 
	int parent(int i) { 
		return (i - 1) / 2; 
	} 

	int lChild(int i) { 
		return (2 * i + 1); 
	} 
	int rChild(int i) { 
		return (2 * i + 2); 
	} 
	int removeMax(); 
	void increaseKey(int i, int newVal); 
	int getMax() { 
		return arr[0]; 
	} 

	int curSize() { 
		return heapSize; 
	} 
	void deleteKey(int i); 
	void insertKey(int x); 
}; 

MaxHeap::MaxHeap(int totSize) { 
	heapSize = 0; 
	maxSize = totSize; 
	arr = new int[totSize]; 
} 

void MaxHeap::insertKey(int x){  
	if (heapSize == maxSize) { 
		cout << "\nOverflow: Could not insertKey\n"; 
		return; 
	} 
	heapSize++; 
	int i = heapSize - 1; 
	arr[i] = x; 

	while (i != 0 && arr[parent(i)] < arr[i]) { 
		swap(arr[i], arr[parent(i)]); 
		i = parent(i); 
	} 
} 

void MaxHeap::increaseKey(int i, int newVal){ 
	arr[i] = newVal; 
	while (i != 0 && arr[parent(i)] < arr[i]) { 
		swap(arr[i], arr[parent(i)]); 
		i = parent(i); 
	} 
} 

int MaxHeap::removeMax(){
	if (heapSize <= 0) 
		return INT_MIN; 
	if (heapSize == 1) { 
		heapSize--; 
		return arr[0]; 
	} 

	int root = arr[0]; 
	arr[0] = arr[heapSize - 1]; 
	heapSize--; 

	MaxHeapify(0); 

	return root; 
} 

void MaxHeap::deleteKey(int i){
	increaseKey(i, INT_MAX); 
	removeMax(); 
} 
 
void MaxHeap::MaxHeapify(int i){ 
	int l = lChild(i); 
	int r = rChild(i); 
	int largest = i; 
	if (l < heapSize && arr[l] > arr[i]) 
		largest = l; 
	if (r < heapSize && arr[r] > arr[largest]) 
		largest = r; 
	if (largest != i) { 
		swap(arr[i], arr[largest]); 
		MaxHeapify(largest); 
	} 
}

int main(){
	MaxHeap h(15); 

	int k, i, n,data, arr[10];  
    cout<<"Enter Size : ";
    cin>>n;
    cout<<"Enter data : ";
    for (int i = 0; i < n; i++)
    {
        cin>>data;
        h.insertKey(data);
    }
	cout<<"The current size of the heap is "<< h.curSize() << "\n"; 
	cout<<"The current maximum element is " << h.getMax()<< "\n"; 
	h.deleteKey(2); 
	cout<<"The current size of the heap is "<< h.curSize()<< "\n"; 
	h.insertKey(15); 
	h.insertKey(5); 
	cout<<"The current size of the heap is "<< h.curSize()<< "\n"; 
	cout<<"The current maximum element is " << h.getMax()<< "\n"; 

	return 0; 
}
