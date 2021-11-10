// https://codeforces.com/problemset/problem/239/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int y, k, n;
    cin >> y >> k >> n;
    int x = k - (y % k);
    if (y + x > n) {
        cout << -1;
    } else {
        while (y + x <= n) {
            cout << x << ' ';
            x += k;
        }
    }
    return 0;
}
