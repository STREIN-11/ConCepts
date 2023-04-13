/*
Input : W = 100
       val[]  = {1, 30}
       wt[] = {1, 50}
Output : 100
There are many ways to fill knapsack.
1) 2 instances of 50 unit weight item.
2) 100 instances of 1 unit weight item.
3) 1 instance of 50 unit weight item and 50
   instances of 1 unit weight items.
We get maximum value with option 2.










Input : W = 8
       val[] = {10, 40, 50, 70}
       wt[]  = {1, 3, 4, 5}       
Output : 110 
We get maximum value with one unit of
weight 5 and one unit of weight 3.*/

#include<bits/stdc++.h>
using namespace std;
int unboundedKnapsack(int W, int n, int val[], int wt[]){
	int dp[W+1];
	memset(dp, 0, sizeof dp);

	for (int i=0; i<=W; i++)
	for (int j=0; j<n; j++)
		if (wt[j] <= i)
			dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);

	return dp[W];
}

// Driver program
int main(){
    int size,data;
    cout<<"How many data : ";
	cin>>size;
    int profit[size];
	int weight[size];
    cout<<"Enter Profit : ";
    for (int i = 0; i < size; i++)
    {
        cin>>profit[i];
    }
    cout<<"Enter weight : ";
    for (int i = 0; i < size; i++)
    {
        cin>>weight[i];
    }
    
	int W;
    cout<<"Enter Capacity : ";
    cin>>W;

	cout << unboundedKnapsack(W, size, profit, weight);

	return 0;
}
