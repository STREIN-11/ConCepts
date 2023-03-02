// C++ program to demonstrate insertion
// into a vector of vectors

#include <iostream>
#include <vector>
using namespace std;

// Defining the rows and columns of
// vector of vectors
#define ROW 4
#define COL 5

int main()
{
	vector<vector<int> > vec;
	int num = 10;
	for (int i = 0; i < ROW; i++) {
		vector<int> v1;

		for (int j = 0; j < COL; j++) {
			v1.push_back(num);
			num += 5;
		}
		vec.push_back(v1);
	}
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}
	return 0;
}
