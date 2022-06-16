#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(v) cout << #v << " = "; for(auto x : v) cout << x << ' '; cout << '\n';
#define pdebug(p) cout << #p << " = " << p.first << ' ' << p.second << '\n';

typedef long long ll;

int lis(vector<int> a)
{
    int n = a.size(), idx;
    vector<int> ret; ret.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] >= ret.back()) {
            ret.push_back(a[i]);
        } else {
            idx = upper_bound(ret.begin(), ret.end(), a[i]) - ret.begin();
            ret[idx] = a[i];
        }
    }
    return ret.size();
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int s;
    float _;
    for (int i = 0; i < n; i++) {
        cin >> s >> _;
        a[i] = s;
    }
    int li = lis(a);
    cout << n - li << '\n';
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
