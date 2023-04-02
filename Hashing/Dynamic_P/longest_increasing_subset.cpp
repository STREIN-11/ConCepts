/*
Input: arr[] = {3, 10, 2, 1, 20}
Output: 3
Explanation: The longest increasing subsequence is 3, 10, 20

Input: arr[] = {3, 2}
Output:1
Explanation: The longest increasing subsequences are {3} and {2}

Input: arr[] = {50, 3, 10, 7, 40, 80}
Output: 4
Explanation: The longest increasing subsequence is {3, 7, 40, 80}*/

#include<bits/stdc++.h>
using namespace std;

int lis(int arr[],int n){
    vector<int> b;
    set<int> s;

    set<int>::iterator it;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    for (it = s.begin(); it != s.end(); it++) {
        b.push_back(*it);
    }

    int m = b.size(), i, j;
    int dp[m + 1][n + 1];

    for (i = 0; i < m + 1; i++) {
        for (j = 0; j < n + 1; j++) {
            dp[i][j] = -1;
        }
    }
    for (i = 0; i < m + 1; i++) {
        for (j = 0; j < n + 1; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (arr[j - 1] == b[i - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
    
}

int main(){
    int size;
    cout<<"Enter Size : ";
    cin>>size;
    int arr[size];
    cout<<"Enter Arry Elements : ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    cout<<"Length of list is: "<<lis(arr,size);
    

return 0;
}