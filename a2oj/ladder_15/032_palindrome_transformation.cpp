#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    s.insert(s.begin(), '*');  // make it 1-indexed, easier to work w/
    int t = 0;
    int left = -1, right = -1;
    for (int i = 1; i <= ceil(n/2); i++) {
        int add = min(abs(s[i] - s[n-i+1]), 26-abs(s[i] - s[n-i+1]));
        t += add;
        if (add != 0) {
            if (left == -1) {
                left = i;
            }
            right = i;
        }
    }
    if (left == -1) {
        cout << 0 << '\n';
        return 0;
    }
    if (n % 2 == 1 && p == ceil(n/2)) {
        t += ceil(n/2) - right;
    } else {
        if (p > ceil(n/2)) {
            p = n+1 - p;
        }
        if (left <= p && p <= right) {
            t += min(abs(p-left), abs(right-p));
        } else {
            t += min(abs(left-p), abs(p-right));
        }
    }
    t += right - left;
    cout << t << '\n';
    return 0;
}