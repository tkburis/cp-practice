// https://codeforces.com/problemset/problem/459/B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll b[n];
    ll mini = INT_MAX, maxi = 0, mini_cnt = 0, maxi_cnt = 0;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        if (t < mini) {
            mini = t;
            mini_cnt = 1;
        } else if (t == mini) {
            mini_cnt++;
        }
        if (t > maxi) {
            maxi = t;
            maxi_cnt = 1;
        } else if(t == maxi) {
            maxi_cnt++;
        }
    }
    
    if (mini == maxi) {
        cout << 0 << ' ' << (n * (n-1))/2;
    } else {
        ll tot = mini_cnt * maxi_cnt;
        cout << maxi - mini << ' ' << tot;
    }
    return 0;
}
