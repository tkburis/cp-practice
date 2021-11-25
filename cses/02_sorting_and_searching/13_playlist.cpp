// https://cses.fi/problemset/task/1141

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> songs(n);
    for (int i = 0; i < n; i++) {
        cin >> songs[i];
    }
    map<int, int> last_seen;
    int best = 0, i = 0;
    for (int j = 0; j < n; j++) {
        if (last_seen.find(songs[j]) != last_seen.end()) {
            i = max(i, last_seen[songs[j]]+1);
        }
        last_seen[songs[j]] = j;
        best = max(best, j-i+1);
    }
    cout << best << '\n';
    return 0;
}

