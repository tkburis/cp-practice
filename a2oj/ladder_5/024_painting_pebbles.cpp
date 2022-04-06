#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int longest = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a[i] = t;
        longest = max(longest, t);
    }
    vector<vector<int>> piles(n);
    int curr = 1;
    bool next = false;
    for (int i = 0; i < longest; i++) {
        if (next) {
            curr++;
            if (curr > k) {
                cout << "NO" << '\n';
                return 0;
            }
            next = false;
        }
        for (int j = 0; j < n; j++) {
            if (i < a[j]) {
                piles[j].push_back(curr);
            } else {
                next = true;
            }
        }
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++) {
            cout << piles[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}