#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll l2(ll x) {
    ll ret = 0;
    while (x >>= 1) ret++;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll sum = 0;
    sort(a.begin(), a.end(), greater<>());
    int i = 0;
    ll mul = l2(n);
    ll curr_width = 1;
    mul /= 2;
    while (i < n) {
        for (; i < curr_width; i++) {
            sum += a[i] * (mul+1);
        }
        curr_width *= 4;
        mul--;
    }
    cout << sum << '\n';
    return 0;
}
