// https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(3, 0);
    for (int day = 0; day < n; day++) {
        vector<int> todays_dp(3, 0);
        for (int& x : todays_dp) {
            cin >> x;
        }
        for (int i = 0; i < 3; i++) {
            int best = 0;
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    best = max(best, todays_dp[i] + dp[j]);
                }
            }
            todays_dp[i] = best;
        }
        dp = todays_dp;
    }
    cout << *max_element(dp.begin(),dp.end());
    return 0;
}
