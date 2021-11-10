// https://codeforces.com/problemset/problem/433/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int x = 0, y = 0;
    for (int i = n-1; i >= 0; i--) {
        if (x >= y) {
            y += a[i];
        } else {
            x += a[i];
        }
    }
    if (x == y) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
