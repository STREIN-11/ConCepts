/*
Algorithm: 
Create a recursive function that takes the following parameters, 
input array, the current index, the output array, or current subset, 
if all the subsets need to be stored then a vector of the array is 
needed if the subsets need to be printed only then this space can 
be ignored.


First, print the subset (output array) that has been sent to 
the function and then run a for loop starting from the ‘index’ 
to n-1 where n is the size of the input array. We use a loop to 
demonstrate that we have exactly n number of choices to choose 
from when adding the first element to our new array. 


Inside the loop, we call the function for the next index 
after inserting that particular index and then in the next call, 
we again have (n-1) choices to choose from and so it goes. 


Whenever a call is made for the last index of the 
array : in that function call, the loop is not run as 
the condition i<A.size() is not fulfilled and hence, 
we backtrack to the last recursion call and call the 
function for the next index after removing the element at 
that current index.*/


#include <bits/stdc++.h>
using namespace std;


void subsetsUtil(vector<int>& A, vector<vector<int> >& res,
				vector<int>& subset, int index){
	res.push_back(subset);
	for (int i = index; i < A.size(); i++) {
		subset.push_back(A[i]);
		subsetsUtil(A, res, subset, i + 1);
		subset.pop_back();
	}

	return;
}

vector<vector<int> > subsets(vector<int>& A)
{
	vector<int> subset;
	vector<vector<int> > res;
	int index = 0;
	subsetsUtil(A, res, subset, index);
	return res;
}
int main(){
	vector<int> array = { 1, 2, 3 };
	vector<vector<int> > res = subsets(array);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	return 0;
}
