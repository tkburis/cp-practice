#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n <= 2) {
        cout << n << '\n';
        return 0;
    }
    vector<int> left(n, 0), right(n, 0);
    left[1] = 1;
    for (int i = 2; i < n; i++) {
        if (a[i-2] < a[i-1]) {
            left[i] = left[i-1] + 1;
        } else {
            left[i] = 1;
        }
    }
    right[n-2] = 1;
    for (int i = n-3; i >= 0; i--) {
        if (a[i+1] < a[i+2]) {
            right[i] = right[i+1] + 1;
        } else {
            right[i] = 1;
        }
    }
    // for (int x : left) cout << x << ' ';
    // cout << '\n';
    // for (int x : right) cout << x << ' ';
    // cout << '\n';
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i < n-1 && a[i] >= a[i+1]) {
            ans = max(ans, right[i] + 1);
        }
        if (i > 0 && i < n-1 && a[i-1] + 1 < a[i+1]) {
            ans = max(ans, left[i] + right[i] + 1);
        }
        if (i > 0 && a[i-1] >= a[i]) {
            ans = max(ans, left[i] + 1);
        }
    }
    cout << ans << '\n';
    return 0;
}
