/*
Longest subsequence such that difference between adjacents is one

Input :  arr[] = {10, 9, 4, 5, 4, 8, 6}
Output :  3
As longest subsequences with difference 1 are, "10, 9, 8", 
"4, 5, 4" and "4, 5, 6"









Input :  arr[] = {1, 2, 3, 2, 3, 7, 2, 1}
Output :  7
As longest consecutive sequence is "1, 2, 3, 2, 3, 2, 1"*/

#include<bits/stdc++.h>
using namespace std;
int longestSubsequence(int n, int arr[])
	{
		if(n==1)
			return 1;
		unordered_map<int,int> mapp;
		int res = 1;
		for(int i=0;i<n;i++){
			if(mapp.count(arr[i]+1) >0 || mapp.count(arr[i]-1)>0){
				mapp[arr[i]]=1+max(mapp[arr[i]+1],mapp[arr[i]-1]);
			}
			else
				mapp[arr[i]]=1;
			res = max(res, mapp[arr[i]]);
		}
		return res;
		//This code is contributed by Akansha Mittal
	}
int main(){
	int n;
    cout<<"Enter Size : ";
    cin>>n;
	int arr[n];
    cout<<"Enter Array Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
	cout << longestSubsequence(n, arr);
	return 0;
}
