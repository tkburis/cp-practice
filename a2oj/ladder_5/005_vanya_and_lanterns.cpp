// https://codeforces.com/problemset/problem/492/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int maxi_diff = 0;
    for (int i = 1; i < n; i++) {
        maxi_diff = max(maxi_diff, a[i] - a[i-1]);
    }
    int ans = max(a[0]*2, max(maxi_diff, (l - a[n-1])*2));
    cout.precision(20);
    cout << fixed << ans/2.0;
    return 0;
}
