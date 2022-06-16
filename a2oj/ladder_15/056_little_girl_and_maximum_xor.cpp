#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(v) cout << #v << " = "; for(auto x : v) cout << x << ' '; cout << '\n';
#define pdebug(p) cout << #p << " = " << p.first << ' ' << p.second << '\n';

typedef long long ll;

// be patient - TEST WITH THEIR CASES BEFORE SUBMITTING
void solve()
{
    ll l, r;
    cin >> l >> r;
    int last = -1;
    int to = 64-min(__builtin_clzll(l), __builtin_clzll(r));
    for (int i = 0; i <= to; i++) {
        if ((l & 1) != (r & 1)) {  // diff
            last = i;
        }
        l >>= 1;
        r >>= 1;
    }
    if (last == -1) {
        cout << 0 << '\n';
        return;
    }
    ll ans = 1;
    while (last--) {
        ans <<= 1;
        ans |= 1;
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
