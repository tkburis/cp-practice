// https://codeforces.com/problemset/problem/260/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    bool ok = false;
    for (int i = 0; i <= 9; i++) {
        if ((a*10 + i) % b == 0) {
            cout << a << i;
            for (int j = 0; j < n-1; j++) {
                cout << 0;
            }
            ok = true;
            break;
        }
    }
    if (!ok) {
        cout << -1;
    }
    return 0;
}
