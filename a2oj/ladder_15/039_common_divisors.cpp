#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9+7
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

typedef long long ll;

vector<string> divide(string s)
{
    int n = s.length();
    vector<string> ret;
    bool ok;
    for (int m = 1; m*m <= n; m++) {
        if (n % m == 0) {
            if (m != n/m) {
                ok = true;
                for (int i = n/m; i < n; i++) {
                    if (s[i] != s[i%(n/m)]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ret.push_back(s.substr(0,n/m));
                }
            }
            ok = true;
            for (int i = m; i < n; i++) {
                if (s[i] != s[i%m]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ret.push_back(s.substr(0,m));
            }
        }
    }
    return ret;
}

void solve()
{
    string s, t;
    cin >> s >> t;
    vector<string> s_divs = divide(s), t_divs = divide(t);
    // vdebug(s_divs); vdebug(t_divs);
    sort(s_divs.begin(), s_divs.end());
    sort(t_divs.begin(), t_divs.end());
    vector<string> inter;
    set_intersection(s_divs.begin(), s_divs.end(), t_divs.begin(), t_divs.end(), back_inserter(inter));
    cout << inter.size() << '\n';
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
