// https://cses.fi/problemset/task/1629

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        times.push_back({b, a});
    }
    sort(times.begin(), times.end());
    int curr_time = 0, ans = 0;
    for (auto p : times) {
        if (p.second >= curr_time) {
            curr_time = p.first;
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
