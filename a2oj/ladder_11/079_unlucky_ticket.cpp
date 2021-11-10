// https://codeforces.com/problemset/problem/160/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int half1[n], half2[n];
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        half1[i] = s[i];
        half2[i] = s[i+n];
    }
    sort(half1, half1+n);
    sort(half2, half2+n);
    bool ok = true;
    if (half1[0] > half2[0]) {
        for (int i = 0; i < n; i++) {
            if (half1[i] <= half2[i]) {
                ok = false;
                break;
            }
        }
    } else if (half1[0] < half2[0]) {
        for (int i = 0; i < n; i++) {
            if (half1[i] >= half2[i]) {
                ok = false;
                break;
            }
        }
    } else {
        ok = false;
    }
    if (ok) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
