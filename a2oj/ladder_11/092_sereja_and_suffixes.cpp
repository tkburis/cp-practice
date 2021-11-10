// https://codeforces.com/problemset/problem/368/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n+1];
    set<int> distincts;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int dp[n];
    for (int i = n; i > 0; i--) {
        distincts.insert(a[i]);
        dp[i] = distincts.size();
    }
    for (int i = 0; i < m; i++) {
        int l;
        cin >> l;
        cout << dp[l] << endl;
    }
    return 0;
}
