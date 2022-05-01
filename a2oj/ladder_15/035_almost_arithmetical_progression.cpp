#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> m;
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (m.find(a[i]) == m.end()) {
            m[a[i]] = index++;
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = m[a[i]];
    }
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i][a[j]] = max(1 + dp[j][a[i]], dp[i][a[j]]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}
