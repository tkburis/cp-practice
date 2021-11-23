// https://cses.fi/problemset/task/1090

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for (int& k : p) {
        cin >> k;
    }
    sort(p.begin(), p.end());
    int i = 0, j = n-1, ans = 0;
    while (i <= j) {
        if (i == j) {
            ans++;
            i++; j--;
        } else {
            if (p[i] + p[j] <= x) {
                ans++;
                i++; j--;
            } else {
                ans++;
                j--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
