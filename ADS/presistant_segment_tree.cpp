#include "bits/stdc++.h"
using namespace std;
#define MAXN 100
struct node{
	int val;
	node* left, *right;
	node() {}
	node(node* l, node* r, int v)
	{
		left = l;
		right = r;
		val = v;
	}
};
int arr[MAXN];
node* version[MAXN];
void build(node* n,int low,int high)
{
	if (low==high)
	{
		n->val = arr[low];
		return;
	}
	int mid = (low+high) / 2;
	n->left = new node(NULL, NULL, 0);
	n->right = new node(NULL, NULL, 0);
	build(n->left, low, mid);
	build(n->right, mid+1, high);
	n->val = n->left->val + n->right->val;
}

void upgrade(node* prev, node* cur, int low, int high,
								int idx, int value){
	if (idx > high or idx < low or low > high)
		return;

	if (low == high){
		cur->val = value;
		return;
	}
	int mid = (low+high) / 2;
	if (idx <= mid){
		cur->right = prev->right;
		cur->left = new node(NULL, NULL, 0);

		upgrade(prev->left,cur->left, low, mid, idx, value);
	}
	else{
		cur->left = prev->left;
		cur->right = new node(NULL, NULL, 0);

		upgrade(prev->right, cur->right, mid+1, high, idx, value);
	}
	cur->val = cur->left->val + cur->right->val;
}

int query(node* n, int low, int high, int l, int r)
{
	if (l > high or r < low or low > high)
	return 0;
	if (l <= low and high <= r)
	return n->val;
	int mid = (low+high) / 2;
	int p1 = query(n->left,low,mid,l,r);
	int p2 = query(n->right,mid+1,high,l,r);
	return p1+p2;
}

int main(int argc, char const *argv[]){
	int n;
    cout<<"Enter Array Size :";
    cin>>n;
    int A[n];
    cout<<"Enter Array Elements : ";
    for (int i = 0; i <n; i++)
        scanf("%d",&A[i]);
        
	for (int i=0; i<n; i++)
	    arr[i] = A[i];

	node* root = new node(NULL, NULL, 0);
	build(root, 0, n-1);

	version[0] = root;
	version[1] = new node(NULL, NULL, 0);
	upgrade(version[0], version[1], 0, n-1, 4, 1);

	version[2] = new node(NULL, NULL, 0);
	upgrade(version[1],version[2], 0, n-1, 2, 10);

	cout << "In version 1 , query(0,4) : ";
	cout << query(version[1], 0, n-1, 0, 4) << endl;

	cout << "In version 2 , query(3,4) : ";
	cout << query(version[2], 0, n-1, 3, 4) << endl;

	cout << "In version 0 , query(0,3) : ";
	cout << query(version[0], 0, n-1, 0, 3) << endl;
	return 0;
}
