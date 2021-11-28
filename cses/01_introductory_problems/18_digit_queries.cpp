// https://cses.fi/problemset/task/2431

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    vector<pair<ll, ll>> ranges;
    ranges.push_back({1, 9});
    for (int i = 1; i <= 15; i++) {
        ll bottom = ranges[i-1].second + 1;
        string s = "";
        s += to_string(i);
        for (int j = 0; j < i; j++) {
            s += '8';
        }
        s += '9';
        ll top = stoll(s, nullptr, 10);
        ranges.push_back({bottom, top});
    }
    int q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        int num_digits;
        for (int i = 0; i < ranges.size(); i++) {
            if (ranges[i].first <= k && k <= ranges[i].second) {
                k -= ranges[i].first;
                num_digits = i + 1;
                break;
            }
        }
        ll digit = k / num_digits + pow(10, num_digits-1);
        ll rem = k % num_digits;
        string digit_s = to_string(digit);
        cout << digit_s[rem] << '\n';
    }
    return 0;
}

