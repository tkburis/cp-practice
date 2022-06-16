#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define dbg(x) cout << #x << " = " << x << '\n';
#define vdbg(v) cout << #v << " = "; for(auto x : v) cout << x << ' '; cout << '\n';
#define pdbg(p) cout << #p << " = " << p.first << ' ' << p.second << '\n';

typedef long long ll;

#define MX 45

// be patient - TEST WITH THEIR CASES BEFORE SUBMITTING
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    int grid[MX][MX];
    memset(grid, 0, sizeof(grid));
    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            grid[i][j] = c-'0';
        }
    }
    int pref[MX][MX];
    memset(pref, 0, sizeof(pref));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] = pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1] + grid[i][j];
        }
    }
    int ans1[MX][MX][MX][MX];
    memset(ans1, 0, sizeof(ans1));
    int chk;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= m; l++) {
                    chk = pref[k][l] - pref[i-1][l] - pref[k][j-1] + pref[i-1][j-1];
                    if (chk == 0) chk = 1;
                    else chk = 0;
                    ans1[i][j][k][l] = ans1[i][j][k-1][l] + ans1[i][j][k][l-1] - ans1[i][j][k-1][l-1] + chk;
                }
            }
        }
    }
    int ans2[MX][MX][MX][MX];
    memset(ans2, 0, sizeof(ans2));
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            for (int k = i; k >= 1; k--) {
                for (int l = j; l >= 1; l--) {
                    ans2[k][l][i][j] = ans2[k+1][l][i][j] + ans2[k][l+1][i][j] - ans2[k+1][l+1][i][j] + ans1[k][l][i][j];
                }
            }
        }
    }
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << ans2[a][b][c][d] << '\n';
    }

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
