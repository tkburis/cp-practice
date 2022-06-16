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
    ll k;
    cin >> k;
    string s;
    cin >> s;
    ll n = s.length();

    vector<ll> ones;
    ones.push_back(-1);
    for (int i = 0; i < n; i++) if (s[i] == '1') ones.push_back(i);
    ones.push_back(n);
    // vdbg(ones);
    ll ans = 0, diff;
    if (k == 0) {
        for (int i = 1; i < ones.size(); i++) {
            diff = ones[i]-ones[i-1]-1;
            ans += diff*(diff+1)/2;
        }
    } else {
        for (int i = 1; i+k < ones.size(); i++) {
            ans += (ones[i]-ones[i-1]) * (ones[i+k] - ones[i+k-1]);
        }
    }
    cout << ans << '\n';
    return;
}

int main()
{
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
