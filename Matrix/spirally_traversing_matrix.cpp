// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int>list;
    
    int top=0,down=r-1,left=0,right=c-1,i;
    
    while(top<=down && left<=right)
    {
        for(i=left;i<=right;i++)
        {
            list.push_back(matrix[top][i]);
            
        }
        top++;
        if(!(top<=down))
        {
            break;
        }
        
        for(i=top;i<=down;i++)
        {
            list.push_back(matrix[i][right]);
            
        }
        right--;
        if(right<left)
        {
            break;
        }
        
        for(i=right;i>=left;i--)
        {
            list.push_back(matrix[down][i]);
            
        }
        down--;
        
        for(i=down;i>=top;i--)
        {
            list.push_back(matrix[i][left]);
            
        }
        left++;
    }
    return list;

    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
