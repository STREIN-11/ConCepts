/*https://www.geeksforgeeks.org/meta-binary-search-one-sided-binary-search/*/

#include<bits/stdc++.h>
using namespace std;

int bsearch(vector<int> A, int key_to_search){
    int n = (int)A.size();
    int lg = log2(n-1)+1;

    int pos = 0;
    for (int i = lg ; i >= 0; i--) {
        if (A[pos] == key_to_search)
            return pos;

        int new_pos = pos | (1 << i);
        if ((new_pos < n) && (A[new_pos] <= key_to_search))
            pos = new_pos;
    }

    return ((A[pos] == key_to_search) ? pos : -1);
}

int main(void){
    int size,key;
    cout<<"Enter Size : ";
    cin>>size;
    int data;
    cout<<"Enter Data : ";
    vector<int> A;
    for (int i = 0; i < size; i++){
        cin>>data;
        A.push_back(data);
    }
    cout<<"Enter The Key : ";
    cin>>key;
    cout << bsearch(A, key) << endl;
 
    return 0;
}
