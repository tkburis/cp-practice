// https://cses.fi/problemset/task/2183

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int& x : coins) {
        cin >> x;
    }
    sort(coins.begin(), coins.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (ans + 1 < coins[i]) {
            break;
        }
        ans += coins[i];
    }
    cout << ans + 1 << '\n';
    return 0;
}

