#include <iostream>
#include <vector>
using namespace std;

void grayCodeUtil(vector<int>& res, int n, int& num){
	if (n == 0) {
		res.push_back(num);
		return;
	}

	grayCodeUtil(res, n - 1, num);

	num = num ^ (1 << (n - 1));
	grayCodeUtil(res, n - 1, num);
}

vector<int> grayCodes(int n)
{
	vector<int> res;

	int num = 0;
	grayCodeUtil(res, n, num);

	return res;
}

int main()
{
	int n;
    cout<<"Enter Number : ";
    cin>>n;
	vector<int> code = grayCodes(n);
	for (int i = 0; i < code.size(); i++)
		cout << "Your Result is : " << code[i] << endl;
	return 0;
}
