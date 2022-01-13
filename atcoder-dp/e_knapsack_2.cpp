// https://atcoder.jp/contests/dp/tasks/dp_e

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int N, W;
    cin >> N >> W;
    vector<pair<ll, ll>> items;
    ll sum_val = 0;
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        sum_val += b;
        items.push_back(make_pair(a, b));
    }
    vector<ll> dp(sum_val+1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = sum_val; j >= 0; j--) {
            if (j - items[i].second >= 0) {
                dp[j] = min(dp[j], dp[j-items[i].second] + items[i].first);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= sum_val; i++) {
        if (dp[i] <= W) {
            ans = max(ans, (ll)i);
        }
    }
    cout << ans << '\n';
    return 0;
}

