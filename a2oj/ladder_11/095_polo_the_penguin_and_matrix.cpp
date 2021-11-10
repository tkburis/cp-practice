// https://codeforces.com/problemset/problem/289/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, d;
    cin >> n >> m >> d;
    int a[n*m], mod;
    for (int i = 0; i < n*m; i++) {
        cin >> a[i];
        if (i == 0) {
            mod = a[i] % d;
        } else {
            if (mod != a[i] % d) {
                cout << -1;
                return 0;
            }
        }
    }
    sort(a, a+n*m);
    int sum = 0, med = a[(n*m)/2];
    for (int n : a) {
        sum += abs(n-med)/d;
    }
    cout << sum << endl;
    return 0;
}
