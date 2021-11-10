// https://codeforces.com/problemset/problem/254/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n, cnts[5001];
    unordered_map<int, vector<int>> indices;
    memset(cnts, 0, sizeof(cnts));
    cin >> n;
    for (int i = 1; i <= 2*n; i++) {
        int t;
        cin >> t;
        cnts[t]++;
        indices[t].push_back(i);
    }
    for (int i : cnts) {
        if (i % 2 == 1) {
            cout << -1;
            return 0;
        }
    }
    for (auto p : indices) {
        for (int i = 0; i < p.second.size(); i+=2) {
            cout << p.second[i] << ' ' << p.second[i+1] << ' ';
        }
        cout << endl;
    }
    return 0;
}
