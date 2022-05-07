#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

typedef long long ll;

ll bigpow(ll a, ll b, ll m)
{
    if (b == 0) return 1;
    if (b & 1) return ((a % m) * bigpow(a, b-1, m)) % m;  // odd
    ll t = bigpow(a, b >> 1, m);
    return (t * t) % m;
}

bool good(int x, int a, int b)
{
    while (x > 0) {
        if (!(x % 10 == a || x % 10 == b)) {
            return false;
            break;
        }
        x /= 10;
    }
    return true;
}

void solve()
{
    int a, b, n;
    cin >> a >> b >> n;
    vector<ll> fact(1000001);
    fact[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    vector<ll> ncr(1000001);
    for (int i = 0; i <= n; i++) {
        ncr[i] = (fact[n] * bigpow(fact[n-i] * fact[i], MOD-2, MOD)) % MOD;
    }
    ll ans = 0;
    ll sum = 0;
    for (int i = 0; i <= n; i++) {
        sum = a*i + b*(n-i);
        if (good(sum, a, b)) {
            ans += ncr[i];
            ans %= MOD;
        }
    }
    cout << ans << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
