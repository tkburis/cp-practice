// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<ll>> memo(101, vector<ll>(100001, -1));
vector<int> w(101), v(101);

ll ks(int n, int c)
{
    ll ret;
    if (memo[n][c] != -1) {
        return memo[n][c];
    }
    if (n == 0 || c == 0) {
        ret = 0;
    } else if (w[n] > c) {
        ret = ks(n-1, c);
    } else {
        ret = max(ks(n-1, c), v[n]+ks(n-1, c-w[n]));
    }
    memo[n][c] = ret;
    return ret;
}

int main()
{
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    cout << ks(n, c);
    return 0;
}
