/*
Input:  S = {1, 2, 2}
Output:  {}, {1}, {2}, {1, 2}, {2, 2}, {1, 2, 2}
Explanation: The total subsets of given set are – {}, {1}, {2}, {2}, {1, 2}, {1, 2}, {2, 2}, {1, 2, 2}
Here {2} and {1, 2} are repeated twice so they are considered only once in the output

Input:  S = {1, 2}
Output:  {}, {1}, {2}, {1, 2}
Explanation: The total subsets of given set are – {}, {1}, {2}, {1, 2}*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > findPowerSet(vector<int>& nums){
	// Size of array to set bit
	int bits = nums.size();

	// Total number of subsets = pow(2,
	// sizeof(arr))
	unsigned int pow_set_size = pow(2, bits);

	// Sort to avoid adding permutation of
	// the substring
	sort(nums.begin(), nums.end());
	vector<vector<int> > ans;

	// To store subset as a list to
	// avoid adding exact duplicates
	vector<string> list;

	// Counter 000..0 to 111..1
	for (int counter = 0; counter < pow_set_size;
		counter++) {
		vector<int> subset;
		string temp = "";

		// Check for the current bit in the counter
		for (int j = 0; j < bits; j++) {
			if (counter & (1 << j)) {
				subset.push_back(nums[j]);

				// Add special character to separate
				// integers
				temp += to_string(nums[j]) + '$';
			}
		}

		if (find(list.begin(), list.end(), temp)
			== list.end()) {
			ans.push_back(subset);
			list.push_back(temp);
		}
	}

	return ans;
}

// Driver code
int main()
{
	vector<int> arr{ 10, 12, 12 };

	vector<vector<int> > power_set = findPowerSet(arr);

	for (int i = 0; i < power_set.size(); i++) {
		for (int j = 0; j < power_set[i].size(); j++)
			cout << power_set[i][j] << " ";
		cout << endl;
	}

	return 0;
}

