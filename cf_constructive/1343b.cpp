#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 4 == 0) {
            cout << "YES" << '\n';
            for (int i = 2; i <= n; i += 2) {
                cout << i << ' ';
            }
            for (int i = 1; i < n - 2; i += 2) {
                cout << i << ' ';
            }
            cout << 3*n/2 - 1 << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}