/*
Given a 2D board of letters and a word. Check if the word exists in the board. The word can be constructed from letters of 
adjacent cells only. ie - horizontal or vertical neighbors. The same letter cell can not be used more than once.



Input: board = {{a,g,b,c},{q,e,e,l},{g,b,k,s}},
word = "geeks"
Output: 1
Explanation: The board is-
a g b c
q e e l
g b k s
The letters which are used to make the
"geeks" are colored.

Input: board = {{a,b,c,e},{s,f,c,s},{a,d,e,e}},
word = "sabfs"
Output: 0
Explanation: The board is-
a b c e
s f c s
a d e e
Same letter can not be used twice hence ans is 0*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        int rows = board.size();
        int cols = board[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0] && dfs(board, i, j, word, 0))
                    return true;
            }
        }
        
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, int row, int col, string& word, int index) {
        if (index == word.length()) return true;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[index])
            return false;
        
        char temp = board[row][col];
        board[row][col] = '#';  // Mark the cell as visited
        
        bool found = dfs(board, row - 1, col, word, index + 1) ||  // Up
                     dfs(board, row + 1, col, word, index + 1) ||  // Down
                     dfs(board, row, col - 1, word, index + 1) ||  // Left
                     dfs(board, row, col + 1, word, index + 1);    // Right
        
        board[row][col] = temp;  // Restore the cell's value
        return found;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends
