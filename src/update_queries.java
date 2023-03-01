/*
 * You are given an array of n elements, initially all a[i] = 0. 
 * Q queries need to be performed. Each query contains three 
 * integers l, r, and x  and you need to change all a[i] to (a[i] | x) 
 * for all l ≤ i ≤ r.

Return the array after executing Q queries.
Input:
N=3, Q=2
U=[[1, 3, 1],
   [1, 3, 2]]

Output:
a[]={3,3,3}

Explanation: 
Initially, all elements of the array are 0. After execution of the
first query, all elements become 1 and after execution of the 
second query all elements become 3.

Example 2:

Input:
N=3, Q=2
U=[[1, 2, 1],
   [3, 3, 2]]

Output:
a[]={1,1,2}

Explanantion:
[0,0,0] => [1,1,0] => [1,1,2]
 */

 //{ Driver Code Starts
//Initial Template for Java

import java.io.*;

class update_queries{
	public static void main(String [] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		while(test-- > 0) {
			String [] str = br.readLine().trim().split(" ");
			int N = Integer.parseInt(str[0]);
			int Q = Integer.parseInt(str[1]);
			int [][] U = new int[Q][3];
			int i = 0;
			while(i < Q) {
				str = br.readLine().trim().split(" ");
				U[i][0] = Integer.parseInt(str[0]);
				U[i][1] = Integer.parseInt(str[1]);
				U[i][2] = Integer.parseInt(str[2]);
				i++;
			}
			Solution obj = new Solution();
			int [] arr = obj.updateQuery(N, Q, U);
			for(int j: arr) {
				System.out.print(j+" ");
			}
			System.out.println();
		}
	}
}
// } Driver Code Ends


//User function Template for Java

class Solution{

 int [] updateQuery(int N, int Q, int [][]U){

        //Write your code here
        int result[] = new int[N];

        for(int k=0;k<Q;k++){

            int l = U[k][0];

            int r = U[k][1];

            int x = U[k][2];

            

            for(int i=l-1;i<r;i++){

                result[i] = result[i] | x ;

            }

        }

        return result;

    }

}