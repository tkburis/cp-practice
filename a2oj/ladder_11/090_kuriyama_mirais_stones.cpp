// https://codeforces.com/problemset/problem/433/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    long long v[n], u[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    copy(v, v+n, u);
    sort(u, u+n);
    long long pref_v[n+1] = {0}, pref_u[n+1] = {0};
    for (int i = 1; i <= n; i++) {
        pref_v[i] = pref_v[i-1] + v[i-1];
        pref_u[i] = pref_u[i-1] + u[i-1];
    }
    cin >> m;
    while (m--) {
        int type, l, r;
        long long sum = 0;
        cin >> type >> l >> r;
        if (type == 1) {
            sum = pref_v[r] - pref_v[l-1];
        } else {
            sum = pref_u[r] - pref_u[l-1];
        }
        cout << sum << endl;
    }
    return 0;
}
