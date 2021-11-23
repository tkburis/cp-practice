// https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a[i] = make_pair(t, i+1);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int target = x - a[i].first;
        int lo = i+1, hi = n-1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (a[mid].first == target) {
                cout << a[i].second << ' ' << a[mid].second << '\n';
                return 0;
            } else if (a[mid].first > target) {
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}

