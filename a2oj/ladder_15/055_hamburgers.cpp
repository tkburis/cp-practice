#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(v) cout << #v << " = "; for(auto x : v) cout << x << ' '; cout << '\n';
#define pdebug(p) cout << #p << " = " << p.first << ' ' << p.second << '\n';

typedef long long ll;

ll fb, nb, pb, fs, ns, ps, fc, nc, pc, r;

ll f(ll x)
{
    return max(0LL, fb*x-nb)*pb + max(0LL, fs*x-ns)*ps + max(0LL, fc*x-nc)*pc;
}

void solve()
{
    string s;
    cin >> s;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;

    fb = 0, fs = 0, fc = 0;
    for (char c : s) {
        if (c == 'B') fb++;
        else if (c == 'S') fs++;
        else if (c == 'C') fc++;
    }

    ll cnt = 0;
    for (ll step = 100000000000000; step >= 1; step /= 2) {
        while (cnt+step < 100000000000000 && f(cnt+step) <= r) cnt += step;
    }
    cout << cnt << '\n';
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
