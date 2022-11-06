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

#include <stdio.h>
#include <stdlib.h>

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
int main(int argc, char const *argv[]){
    int n;
    printf("Enter Array Size : ");
    scanf("%d",&n);
    int arr[n];


    return 0;
}
