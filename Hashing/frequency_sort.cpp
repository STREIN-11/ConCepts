#include <bits/stdc++.h>
using namespace std;

bool sortByVal(const pair<int, int> &a,
               const pair<int, int> &b)
{

    if (a.second == b.second)
        return a.first < b.first;

    return a.second > b.second;
}

vector<int> sortByFreq(int a[], int n)
{

    vector<int> res;

    unordered_map<int, int> m;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; ++i)
    {
        m[a[i]]++;
    }

    copy(m.begin(), m.end(), back_inserter(v));

    sort(v.begin(), v.end(), sortByVal);

    for (int i = 0; i < v.size(); ++i)
        while (v[i].second--)
        {
            res.push_back(v[i].first);
        }

    return res;
}

int main()
{

    int a[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> res;
    res = sortByFreq(a, n);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}
