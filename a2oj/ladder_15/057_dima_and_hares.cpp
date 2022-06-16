#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(v) cout << #v << " = "; for(auto x : v) cout << x << ' '; cout << '\n';
#define pdebug(p) cout << #p << " = " << p.first << ' ' << p.second << '\n';

typedef long long ll;

// be patient - TEST WITH THEIR CASES BEFORE SUBMITTING
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    for (int &x : c) cin >> x;
    vector<vector<int>> dp(n, vector<int>(2));
    dp[n-1][0] = a[n-1];
    dp[n-1][1] = b[n-1];
    for (int i = n-2; i >= 0; i--) {
        dp[i][0] = max(dp[i+1][0] + b[i], dp[i+1][1] + a[i]);
        dp[i][1] = max(dp[i+1][0] + c[i], dp[i+1][1] + b[i]);
        // debug(i); debug(dp[i][0]); debug(dp[i][1]);
    }
    cout << dp[0][0] << '\n';
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
