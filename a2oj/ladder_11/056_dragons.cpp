// https://codeforces.com/problemset/problem/230/A

#include <bits/stdc++.h>
using namespace std;

bool SpecialSort(const pair<int, int> a, const pair<int, int> b)
{
    if (a.first < b.first) {
        return true;
    } else if (a.first == b.first) {
        if (a.second > b.second) {
            return true;
        }
    }
    return false;
}

int main()
{
    int s, n;
    cin >> s >> n;
    vector<pair<int, int>> dragons(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        dragons[i] = make_pair(x, y);
    }
    sort(dragons.begin(), dragons.end(), SpecialSort);
    for (auto dragon : dragons) {
        if (dragon.first >= s) {
            cout << "NO";
            return 0;
        } else {
            s += dragon.second;
        }
    }
    cout << "YES";
    return 0;
}
