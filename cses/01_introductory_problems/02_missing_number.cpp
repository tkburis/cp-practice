// https://cses.fi/problemset/task/1083

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll correct_sum = n, curr_sum = 0;
    while (--n) {
        ll t;
        cin >> t;
        correct_sum += n;
        curr_sum += t;
    }
    cout << correct_sum - curr_sum << endl;
    return 0;
}
