#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

typedef long long ll;

void solve()
{
    int n, k, d;
    cin >> n >> k >> d;
    vector<vector<ll>> dp(101, vector<ll>(2, 0));
    dp[0][0] = 1; dp[0][1] = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 1; j < d && i+j <= 100; j++) {
            dp[i+j][0] = (dp[i+j][0] + dp[i][0]) % MOD;
            dp[i+j][1] = (dp[i+j][1] + dp[i][1]) % MOD;
        }
        for (int j = d; j <= k && i+j <= 100; j++) {
            dp[i+j][1] = (dp[i+j][1] + dp[i][0]) % MOD;
            dp[i+j][1] = (dp[i+j][1] + dp[i][1]) % MOD;
        }
    }
    cout << dp[n][1] << '\n';
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
