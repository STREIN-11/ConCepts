/*
Input: N = 3
Output:  4
Explanation: Numbers from 1 to 3: {1, 2, 3}
Binary Representation of 1: 01 -> Set bits = 1
Binary Representation of 2: 10 -> Set bits = 1
Binary Representation of 3: 11 -> Set bits = 2
Total set bits from 1 till 3 = 1 + 1 + 2 = 4*/

#include <iostream>
using namespace std;

unsigned int countSetBitsUtil(unsigned int x);

unsigned int countSetBits(unsigned int n){
	int bitCount = 0; 
	for (int i = 1; i <= n; i++)
		bitCount += countSetBitsUtil(i);

	return bitCount;
}

unsigned int countSetBitsUtil(unsigned int x)
{
	if (x <= 0)
		return 0;
	return (x % 2 == 0 ? 0 : 1) + countSetBitsUtil(x / 2);
}

int main(){
	int n;
    cout<<"Enter A Number : ";
    cin>>n;
	cout << "Total set bit count is " << countSetBits(n);
	return 0;
}