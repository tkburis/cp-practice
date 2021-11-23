// https://cses.fi/problemset/task/1643

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll x;
    cin >> x;
    ll curr = x, best = x;
    for (int i = 1; i < n; i++) {
        cin >> x;
        curr = max(x, curr + x);
        best = max(best, curr);
    }
    cout << best << '\n';
    return 0;
}

