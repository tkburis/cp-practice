#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll s = 0, mx = 0;
    ll a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s += a;
        mx = max(mx, a);
    }
    cout << max((s+n-2)/(n-1), mx) << '\n';
    return 0;
}