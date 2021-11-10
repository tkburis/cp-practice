// https://codeforces.com/problemset/problem/236/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int prod = a * b * c, divs[prod+1];
    memset(divs, 0, sizeof(divs));
    for (int i = 1; i <= prod; i++) {
        for (int j = i; j <= prod; j+=i) {
            divs[j]++;
        }
    }
    int ans = 0, mod = 1073741824;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                ans += divs[i*j*k];
                ans %= mod;
            }
        }
    }
    cout << ans;
    return 0;
}
