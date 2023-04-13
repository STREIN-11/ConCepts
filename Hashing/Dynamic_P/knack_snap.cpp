#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	int K[n + 1][W + 1];
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1]
								+ K[i - 1][w - wt[i - 1]],
							K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	return K[n][W];
}

int main()
{
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
	int n = sizeof(profit) / sizeof(profit[0]);
	printf("%d", knapSack(W, weight, profit, size));
	return 0;
}
