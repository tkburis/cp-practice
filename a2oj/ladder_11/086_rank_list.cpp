// https://codeforces.com/problemset/problem/166/A

#include <bits/stdc++.h>
using namespace std;

bool sorter(const pair<pair<int, int>, int> a, const pair<pair<int, int>, int> b) {
    return (a.first.first > b.first.first) || (a.first.first == b.first.first && a.first.second < b.first.second);
}

int main()
{
    int n, k;
    cin >> n >> k;
    map<pair<int, int>, int> cnts;
    for (int i = 0; i < n; i++) {
        int p, t;
        cin >> p >> t;
        cnts[make_pair(p, t)]++;
    }
    vector<pair<pair<int, int>, int>> vec_cnts;
    for (auto p : cnts) {
        vec_cnts.push_back(make_pair(p.first, p.second));
    }
    sort(vec_cnts.begin(), vec_cnts.end(), sorter);
    int curr_k = 0;
    for (auto p : vec_cnts) {
        curr_k += p.second;
        if (curr_k >= k) {
            cout << p.second;
            break;
        }
    }
    return 0;
}
