#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define dbg(x) cout << #x << " = " << x << '\n';
#define vdbg(v) cout << #v << " = "; for(auto x : v) cout << x << ' '; cout << '\n';
#define pdbg(p) cout << #p << " = " << p.first << ' ' << p.second << '\n';

typedef long long ll;

// be patient - TEST WITH THEIR CASES BEFORE SUBMITTING
void solve()
{
    int n;
    cin >> n;
    ll num = 0, sum = 0;
    ll t, a, x, k;
    vector<ll> mask(n+1), v(n+1);
    while (n--) {
        cin >> t;
        if (t == 1) {
            cin >> a >> x;
            sum += x * min(num+1, a);
            mask[min(num+1, a)-1] += x;
        } else if (t == 2) {
            cin >> k;
            num++;
            v[num] = k;
            sum += k;
        } else {
            mask[num-1] += mask[num];
            sum -= (mask[num] + v[num]);
            v[num] = 0;
            mask[num] = 0;
            num--;
        }
        cout << setprecision(10) << (sum/(long double)(num+1)) << '\n';
    }
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
