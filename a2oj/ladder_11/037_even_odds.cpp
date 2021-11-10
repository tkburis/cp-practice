// https://codeforces.com/problemset/problem/318/A

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n = 0, k = 0, f = 0, x = 0;
    cin >> n >> k;
    if (n % 2 == 0) {
        f = n / 2;
    } else {
        f = (n / 2) + 1;
    }
    
    if (k > f) {
        x = 2 * (k - f);
    } else {
        x = (2 * k) - 1;
    }
    cout << x;
    return 0;
}
