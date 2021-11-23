// https://cses.fi/problemset/task/1091

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    multiset<int> h;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        h.insert(t);
    }
    for (int i = 0; i < m; i++) {
        int curr;
        cin >> curr;
        auto ok = h.upper_bound(curr);
        if (ok == h.begin()) {
            cout << -1 << endl;
            continue;
        }
        ok--;
        cout << *ok << endl;
        h.erase(ok);
    }
    return 0;
}
