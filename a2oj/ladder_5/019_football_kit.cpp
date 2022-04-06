#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> home_freqs;
    vector<pair<int, int>> teams;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        home_freqs[x]++;
        teams.push_back(make_pair(x, y));
    }
    for (auto p : teams) {
        int home_kits = home_freqs[p.second];
        home_kits += n-1;
        cout << home_kits << ' ' << (n-1)*2 - home_kits << '\n';
    }
    return 0;
}