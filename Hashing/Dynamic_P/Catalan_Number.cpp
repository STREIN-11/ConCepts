#include<bits/stdc++.h>
using namespace std;

unsigned long int catl(unsigned int c){
    unsigned long int catalan[c+1];
    catalan[0] = catalan[1] = 1;
    for(int i = 2; i<=c; i++){
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }
    return catalan[c];
}
int main(){
    int start,size,data;
    cout<<"Enter Start point : ";
    cin>>start;
    cout<<"Enter End point : ";
    cin>>size;
    cout<<"Result : ";
    for(int i=start; i<size; i++){
        cout<< catl(i) << " ";
    }
return 0;
}
