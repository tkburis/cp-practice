#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define dbg(x) cout << #x << " = " << x << '\n';
#define vdbg(v) cout << #v << " = "; for(auto x : v) cout << x << ' '; cout << '\n';
#define pdbg(p) cout << #p << " = " << p.first << ' ' << p.second << '\n';

typedef long long ll;

// be patient - TEST WITH THEIR CASES BEFORE SUBMITTING
void solve()
{
    int n;
    cin >> n;
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, LONG_LONG_MAX));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dist[i][j];
        }
    }
    stack<ll> sums;
    vector<int> nodes(n);
    for (int i = n-1; i >= 0; i--) cin >> nodes[i];
    for (int k = 0; k < n; k++) {
        // cout << "current nodes ";
        // for (int i = 0; i <= k; i++) cout << nodes[i] << ' ';
        // cout << '\n';

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // cout << "from " << nodes[i] << " to " << nodes[j] << ':';
                dist[nodes[i]][nodes[j]] = min(dist[nodes[i]][nodes[j]],
                                               dist[nodes[i]][nodes[k]] + dist[nodes[k]][nodes[j]]);
            }
        }
        ll sum = 0;
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                sum += dist[nodes[i]][nodes[j]];
            }
        }
        sums.push(sum);
    }
    while (!sums.empty()) {
        cout << sums.top() << ' '; sums.pop();
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
