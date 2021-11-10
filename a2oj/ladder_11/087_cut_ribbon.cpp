// https://codeforces.com/problemset/problem/189/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int dp[4001];  // dp[x] = max # ribbon pieces when length x is cut
    memset(dp, 0, sizeof(dp));
    dp[a] = 1;
    dp[b] = 1;
    dp[c] = 1;
    for (int i = 1; i <= n; i++) {
        if (dp[i] == 0) {
            continue;
        }
        if (i+a <= n) {
            dp[i+a] = max(dp[i+a], dp[i]+1);
        }
        if (i+b <= n) {
            dp[i+b] = max(dp[i+b], dp[i]+1);
        }
        if (i+c <= n) {
            dp[i+c] = max(dp[i+c], dp[i]+1);
        }
    }
    cout << dp[n];
    return 0;
}
