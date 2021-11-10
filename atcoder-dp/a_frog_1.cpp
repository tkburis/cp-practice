// https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 2; j++) {
            if (i+j < n) {
                dp[i+j] = min(dp[i+j], dp[i] + abs(h[i] - h[i+j]));
            }
        }
    }
    cout << dp[n-1];
    return 0;
}
