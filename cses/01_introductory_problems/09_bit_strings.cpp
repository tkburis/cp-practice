// https://cses.fi/problemset/task/1617

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long ans = 1, MOD = 1000000007;
    for (int i = 0; i < n; i++) {
        ans = ((ans % MOD) * 2) % MOD;
    }
    cout << ans << endl;
    return 0;
}
