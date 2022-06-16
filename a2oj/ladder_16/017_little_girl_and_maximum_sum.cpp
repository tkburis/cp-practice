#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define dbg(x) cout << #x << " = " << x << '\n';
#define vdbg(v) cout << #v << " = "; for(auto x : v) cout << x << ' '; cout << '\n';
#define pdbg(p) cout << #p << " = " << p.first << ' ' << p.second << '\n';

typedef long long ll;

template<class T> struct fentree
{
    int n;
    vector<T> tree;
    void set(int size) {
        n = size;
        tree.assign(n+1, 0);
    }
    void update(int i, T v) {  // 0-indexed
        i++;
        while (i <= n) {
            tree[i] += v;
            i += i & (-i);
        }
    }
    T query(int i) {  // sum(0...i) inclusive, 0-indexed
        T s = 0;
        i++;
        while (i > 0) {
            s += tree[i];
            i -= i & (-i);
        }
        return s;
    }
};

// be patient - TEST WITH THEIR CASES BEFORE SUBMITTING
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    fentree<int> fen;
    fen.set(n+2);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        fen.update(l, 1);
        fen.update(r+1, -1);
        // vdbg(fen.tree);
    }
    vector<int> mask(n);
    for (int i = 0; i < n; i++) {
        mask[i] = fen.query(i);
    }
    // vdbg(mask);
    sort(mask.begin(), mask.end(), greater<>());
    sort(a.begin(), a.end(), greater<>());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1LL * mask[i] * a[i];
    }
    cout << ans << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
