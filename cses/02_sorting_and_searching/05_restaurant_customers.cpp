// https://cses.fi/problemset/task/1619

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> line;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        line.push_back({a, 1});
        line.push_back({b, -1});
    }
    sort(line.begin(), line.end());
    int best = 0, curr = 0;
    for (auto p : line) {
        curr += p.second;
        best = max(best, curr);
    }
    cout << best << '\n';
    return 0;
}

