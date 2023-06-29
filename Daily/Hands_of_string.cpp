/*
Alice has some cards, each card has one number written on it. 
She wants to rearrange the cards into groups so that each group is
of size groupSize, and consists of groupSize consecutive cards.
Given an integer array hand of size N where hand [ i ] is the value 
written on the ith card and an integer groupSize, return true if she 
can rearrange the cards, or false otherwise.

Input:

N = 9
groupSize = 3
hand[ ] = {1, 2, 3, 6, 2, 3, 4, 7, 8}
Output: true
Explanation: 
Alice's hand can be rearranged as {1, 2, 3} , {2, 3, 4}, {6, 7, 8}. 
There are three groups with size 3. Each group has 3 consecutive cards.

Input:
N = 5
groupSize = 2
hand[ ] = {1, 2, 3, 4, 5}
Output: false
Explanation: 
Alice's hand cannot be rearranged into groups of 2. Since there are 
5 cards and 5 cards cannot be divided into groups of 2.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        map<int,int> f;
        for(int i: hand)    f[i]++;
        for(auto i: f){
            int v=i.first;
            int c=i.second;
            if(c==0)    continue;
            for(int j=v;j<v+groupSize;j++){
                if(f[j]==0 or f[j]<c)  return false;
                f[j]-=c;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
