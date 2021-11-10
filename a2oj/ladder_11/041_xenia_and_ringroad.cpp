// https://codeforces.com/problemset/problem/339/B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n = 0, m = 0;
    cin >> n >> m;
    ll cnt = 0, prev = 0;
    cin >> prev;
    cnt += prev - 1;
    for (ll i = 1; i < m; i++) {
        ll a = 0;
        cin >> a;
        if (a < prev) {
            cnt += n - prev + a;
        } else if (a > prev) {
            cnt += a - prev;
        }
        prev = a;
    }
    cout << cnt;
    return 0;
}
