#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9+7
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> c(n+1);
    map<int, set<int>> qs;
    for (int i = 1; i <= n; i++) cin >> c[i];
    map<int, vector<int>> adjs;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adjs[a].push_back(b);
        adjs[b].push_back(a);
    }
    for (auto p : adjs) {
        for (int adj : p.second) {
            if (c[adj] != c[p.first]) qs[c[p.first]].insert(c[adj]);
        }
    }
    int mx = 0;
    for (int x : c) {
        if (x != 0) mx = max(mx, (int)qs[x].size());
    }
    int mn = INT_MAX;
    for (int x : c) {
        if (x != 0 && (int)qs[x].size() == mx && x <= mn) {
            mn = x;
        }
    }
    cout << mn << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
