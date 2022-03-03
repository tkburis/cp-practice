#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    bool ok = false;

    if (n > m) {
        ok = true;
    // } else if (n == m) {
    //     sort(a.begin(), a.end());
    //     sort(b.begin(), b.end());
    //     for (int i = 0; i < n; i++) {
    //         if (a[i] > b[i]) {
    //             ok = true;
    //             break;
    //         }
    //     }
    } else {  // n < m
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for (int i = m-n; i < m; i++) {
            if (a[i - (m-n)] > b[i]) {
                ok = true;
                break;
            }
        }
    }

    if (ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';

    return 0;
}