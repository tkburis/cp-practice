// https://codeforces.com/problemset/problem/214/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, cnt = 0;
    cin >> n >> m;
    int a = 0;
    while (a * a <= n) {
        int b = n - (a * a);
        if (a + (b * b) == m) {
            cnt++;
        }
        a++;
    }
    cout << cnt;
    return 0;
}
