// https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> dp(n+6, 0);
    dp[5] = 1;
    for (int i = 6; i <= n+5; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]) % 1000000007;
    }
    cout << dp[n+5] << '\n';
    return 0;
}

