#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9+7
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> pnts(100002);
    for (ll x : a) {
        pnts[x] += x;
    }
    vector<ll> dp(100002);
    dp[1] = pnts[1];
    dp[2] = max(dp[1], pnts[2]);
    for (int i = 2; i <= 100000; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + pnts[i]);
    }
    ll mx = 0;
    for (ll x : dp) mx = max(mx, x);
    cout << mx << '\n';
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
