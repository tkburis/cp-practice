#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(v) cout << #v << " = "; for(auto x : v) cout << x << ' '; cout << '\n';
#define pdebug(p) cout << #p << " = " << p.first << ' ' << p.second << '\n';

typedef long long ll;

map<int, vector<int>> adjs;
vector<ll> vals;

pair<ll, ll> dfs(int from, int node)  // (+ needed, - needed)
{
    int v = vals[node];
    // debug(node); debug(v);
    if (adjs[node].size() == 1 && adjs[node][0] == from) {  // leaf
        pair<ll, ll> ret;
        if (v > 0) {
            ret = make_pair(0, v);
        } else {
            ret = make_pair(-v, 0);
        }
        // pdebug(ret);
        return ret;
    }
    pair<ll, ll> ret = {0, 0}, t;
    for (int adj : adjs[node]) if (adj != from) {
        t = dfs(node, adj);
        ret.first = max(ret.first, t.first);
        ret.second = max(ret.second, t.second);
    }
    if (v >= 0) {
        if (ret.second <= ret.first + v) {
            ret.second = ret.first + v;
        } else {
            ret.first = ret.second - v;
        }
    } else {
        if (ret.first <= ret.second - v) {
            ret.first = ret.second - v;
        } else {
            ret.second = ret.first + v;
        }
    }
    // pdebug(ret);
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        adjs[a].push_back(b);
        adjs[b].push_back(a);
    }
    vals.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> vals[i];
    pair<ll, ll> ans = dfs(-1, 1);
    cout << ans.first + ans.second << '\n';
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
