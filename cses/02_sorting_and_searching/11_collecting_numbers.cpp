// https://cses.fi/problemset/task/2216

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> idx_of;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        idx_of[t] = i;
    }
    int ans = 1, curr_idx = 0;
    for (auto p : idx_of) {
        if (p.second < curr_idx) {
            ans++;
        }
        curr_idx = p.second;
    }
    cout << ans << '\n';
    return 0;
}

