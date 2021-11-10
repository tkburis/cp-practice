// https://codeforces.com/problemset/problem/222/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = k+1; i <= n; i++) {
        if (a[i] != a[k]) {
            cout << -1;
            return 0;
        }
    }
    int ans;
    for (ans = k-1; ans > 0; ans--) {
        if (a[ans] != a[k]) {
            break;
        }
    }
    cout << ans;
    return 0;
}
