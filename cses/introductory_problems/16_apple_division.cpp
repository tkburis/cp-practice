// https://cses.fi/problemset/task/1623
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> p(n);
    ll tot_sum = 0;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        p[i] = t;
        tot_sum += t;
    }
    ll diff = INT_MAX;
    for (int b = 0; b < (1 << n); b++) {
        ll sub_sum = 0;
        for (int j = 0; j < n; j++) {
            if (b & (1 << j)) {
                sub_sum += p[j];
            }
        }
        diff = min(diff, abs(sub_sum - (tot_sum - sub_sum)));
    }
    cout << diff << endl;
    return 0;
}
