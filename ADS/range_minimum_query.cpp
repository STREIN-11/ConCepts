//  0 1 2 3 4 5
// [2,5,1,4,9,3]
//                1
//      /        [0-5]      \
//     /                     \
//     1[0-2]                3 [3-5]
//   /   \                 /    \
//  2     1           [3-4]4     3 
// / [0-1] \             /  \
// 2        5           4    9

#include <bits/stdc++.h>
using namespace std;

int min(int x,int y){return (x<y)? x: y;}
int getmid(int x,int y){return x+(y-x)/2;}

int rmqutil(int *st,int ss,int se,int qs,int qe,int index){
    if (qs <= ss && qe >= se)
        return st[index];

    if (se < qs || ss > qe)
        return __INT_MAX__;

    int mid = getmid(ss,se);
    return min(rmqutil(st, ss, mid, qs, qe, 2*index+1),
               rmqutil(st, mid+1, se, qs, qe, 2*index+2));
}

int rmq(int *st,int n,int qs,int qe){
    if(qs<0 || qe>n-1 || qs>qe){
        printf("Invalid Input");
        return -1;
    }
    return rmqutil(st,0, n-1, qs,qe,0);
}

int constructSTutil(int arr[],int ss,int se,int *st,int si){
    if(ss==se){
        st[si]=arr[ss];
        return arr[ss];
    }   
    int mid = getmid(ss,se);
    st[si] = min(constructSTutil(arr, ss, mid, st, si*2+1),constructSTutil(arr, mid+1, se, st, si*2+2)); 
    return st[si];
}

int *constructST(int arr[],int n){
    int x = (int)(ceil(log2(n))); 
  
    // Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1; 
  
    int *st = new int[max_size]; 

    constructSTutil(arr, 0, n-1, st, 0);

    return st;
}

int main(int argc, char const *argv[]){
    int n;
    printf("Enter Array Size : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Array Elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int *st = constructST(arr,n);
    int qs,qe;
    printf("Enter Start index : ");
    scanf("%d",&qs);
    printf("Enter End index : ");
    scanf("%d",&qe);
    cout<<"Minimum of values in range ["<<qs<<", "<<qe<<"] "<<"is = "<<rmq(st, n, qs, qe)<<endl;

    return 0;
}
