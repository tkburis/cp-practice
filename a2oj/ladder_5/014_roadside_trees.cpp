#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0, curr_height = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        ans += abs(t - curr_height) + 1;
        curr_height = t;
    }
    cout << ans + n - 1 << '\n';
    return 0;
}