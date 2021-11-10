// https://codeforces.com/problemset/problem/451/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    map<int, int> mp;
    sort(b, b+n);
    for (int i = 0; i < n; i++) {
        mp[b[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        a[i] = mp[a[i]];
    }
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] != i) {
            l = i;
            break;
        }
    }
    for (int i = n-1; i > -1; i--) {
        if (a[i] != i) {
            r = i;
            break;
        }
    }
    if (l == r && r == -1) {
        cout << "yes\n1 1" << endl;
    } else {
        reverse(a+l, a+r+1);
        if (is_sorted(a, a+n)) {
            cout << "yes\n" << l+1 << ' ' << r+1 << endl;
        } else {
            cout << "no";
        }
    }
}
