// https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int& i : c) {
        cin >> i;
    }
    vector<int> dp(x+1, 1e9);
    for (int k : c) {
        if (k <= x) {
            dp[k] = 1;
        }
    }
    for (int i = 1; i <= x; i++) {
        for (int k : c) {
            if (i + k <= x) {
                dp[i+k] = min(dp[i+k], dp[i]+1);
            }
        }
    }
    if (dp[x] == 1e9) {
        cout << -1 << '\n';
    } else {
        cout << dp[x] << '\n';
    }
    return 0;
}
