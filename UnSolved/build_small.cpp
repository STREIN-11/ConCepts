/*
Given a number k and string num of digits (0 to 9) denoting a positive integer. Find a string denoting the lowest integer number possible 
by removing k digits from num, without changing their order.
Note: num will not contain any leading zero.
Input:
k = 2
num = "143729"
Output: "1329"
Explanation: 1329 is the minimum number
possible after removing '4' and '7'.

Input:
k = 3
num = "10056"
Output: "0"
Explanation: 0 is the minimum number
possible after removing '1' , '5' and '6'.*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    deque <char> dq;
    int n = num.size();
    int removed = 0;
    for(int i = 0; i < n; i++){
        while(removed < k && dq.size() && dq.back() > num[i]){
            dq.pop_back();
            removed++;
        }
        dq.push_back(num[i]);
    }
    while(removed < k || dq.size() > 1 && dq.front() == '0'){
       if(removed < k){    
         dq.pop_back();
         removed++;
       } else{
           dq.pop_front();
       }
    }
    return string(dq.begin(), dq.end());
}