/*https://www.geeksforgeeks.org/sentinel-linear-search/*/

#include <iostream>
using namespace std;

void sentinelSearch(int arr[], int n, int key){
	int last = arr[n - 1];
	arr[n - 1] = key;
	int i = 0;

	while (arr[i] != key)
		i++;
	arr[n - 1] = last;

	if ((i < n - 1) || (arr[n - 1] == key))
		cout << key << " is present at index " << i;
	else
		cout << "Element Not found";
}

int main(){
    int size,key;
    cout<<"Enter Size : ";
    cin>>size;
    int arr[size];
	// int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Enter Array Elements : ";
    for (int i = 0; i < size; i++){
        cin>>arr[i];
    }
    cout<<"Enter The Key : ";
    cin>>key;
    sentinelSearch(arr, size, key);
    return 0;
}
