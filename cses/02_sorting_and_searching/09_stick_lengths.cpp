// https://cses.fi/problemset/task/1074

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int&x : p) {
        cin >> x;
    }
    sort(p.begin(), p.end());
    int med = p[n/2];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(p[i] - med);
    }
    cout << ans << '\n';
    return 0;
}

