/*
You are given a sorted array a of length n. For each i(0<=i<=n-1), you have to make all the elements of the array
 from index 0 till i equal, using minimum number of operations. In one operation you either increase or decrease the array element by 1.
You have to return a list which contains the minimum number of operations for each i, to accomplish the above task.
Note:
1. 0-based indexing.
2. For each index, you need to consider the same array which was given to you at the start.







Input:
N=4
A={1,6,9,12}

Output:
0 5 8 14

Explanation:
For i=0, We do not need to perform any 
operation, our array will be {1}->{1}.
And minimum number of operations
will be 0.

For i=1, We can choose to convert all 
the elements from 0<=j<=i to 4, our 
array will become {1,6}->{4,4}. And 
minimum number of operations will be 
|1-4|+|6-4|=5.

For i=2, We can choose to convert all 
the elements from 0<=j<=i to 6, our 
array will become {1,6,9}->{6,6,6} and 
the minimum number of operations will 
be |1-6|+|6-6|+|9-6|=8.

Similarly, for i=3, we can choose to 
convert all the elements to 8, 
{1,6,9,12}->{8,8,8,8}, and the 
minimum number of operations will be 14.


Example 2:

Input:
N=7
A={1,1,1,7,7,10,19}

Output:
0 0 0 6 12 21 33

Explanation:
Possible operations could be:
{1}->{1}
{1,1}->{1,1}
{1,1,1}->{1,1,1}
{1,1,1,7}->{1,1,1,1}
{1,1,1,7,7}->{1,1,1,1,1}
{1,1,1,7,7,10}->{5,5,5,5,5,5}
{1,1,1,7,7,10,19}->{7,7,7,7,7,7,7}*/

//{ Driver Code Starts
import java.util.*;
import java.io.*;

class optimal_array{
    public static void main(String args[])throws IOException
    {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t=Integer.parseInt(in.readLine());
        while(t-->0){
            int n=Integer.parseInt(in.readLine());
            String s[]=in.readLine().trim().split(" ");
            int a[]=new int[n];
            for(int i=0;i<n;i++){
                a[i]=Integer.parseInt(s[i]);
            }
            Solution ob=new Solution();
            long arr[]=ob.optimalArray(n,a);
            for(long i:arr){
                out.print(i+" ");
            }
            out.println();
        }
        out.close();
    }
}
// } Driver Code Ends




class Solution {

    public long[] optimalArray(int n,int a[])

    {

        long ans[]=new long[n];

        ans[0]=0;

        long x=a[0];

        long newm=0;

        for(int i=1;i<n;i++){

            if(i%2==0){

                newm=a[i/2];

                ans[i]=ans[i-1]+a[i]-newm;

            }

            else{

                newm=(a[i/2]+a[i/2+1])/2;

                ans[i]=ans[i-1]+(newm-x)+(a[i]-newm);

            }

            x=newm;

        }

        return ans;

    }

}
        


