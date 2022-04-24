// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);
// Driver program to test above function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}
// } Driver Code Ends
/*you are required to complete this method*/
int convertFive(int n) {
    // Your code here
    if (n == 0)
return 0;
// Extract the last digit and change it if needed
int digit = n % 10;
if (digit == 0)
digit = 5;
// Convert remaining digits and append the last digit
return convertFive(n/10) * 10 + digit;
}

int Convert(int n)
{
if (n == 0)
return 1;
else
return convertFive(n);
}
