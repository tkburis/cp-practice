// https://codeforces.com/problemset/problem/327/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << 2 << ' ';
    int cnt = 0, cur = 3;
    while (cnt < n-1) {
        bool ok = true;
        for (int f = 2; f * f <= cur; f++) {
            if (cur % f == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << cur << ' ';
            cnt++;
        }
        cur++;
    }
    return 0;
}
