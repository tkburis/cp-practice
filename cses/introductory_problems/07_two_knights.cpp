// https://cses.fi/problemset/task/1072

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll dp[n+1];  // number of ways knights CAN attack each other, i.e. 2*number of 2x3 rectangles you can fit
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 8;
    for (ll k = 4; k <= n; k++) {
        dp[k] = dp[k-1] + 4*(k-1) + 4*(k-2) - 4;
    }
    for (ll i = 1; i <= n; i++) {
        ll ans = ((i*i) * (i*i-1)) / 2 - dp[i];
        cout << ans << endl;
    }
    return 0;
}
