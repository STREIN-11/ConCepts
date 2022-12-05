#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
bool has[MAX + 1][2];

bool search(int x){
    if (x > 0)
    {
        if (has[x][0] == 1)
            return true;
        else
            return false;
    }
    
    x = abs(x);
    if (has[x][1] == 1)
        return true;
    return false;
}

void insert(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
            has[a[i]][0] = 1;
        else
            has[abs(a[i])][1] = 1;
    }
}

int main()
{
    int size, x;
    cout << "Enter Size : ";
    cin >> size;
    int arr[size];
    cout << "Enter Array elements: ";
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    insert(arr, size);
    cout << "Search : ";
    cin >> x;
    if (search(x) == true)
        cout << "Found";
    else
        cout << "Not Found";

    return 0;
}
