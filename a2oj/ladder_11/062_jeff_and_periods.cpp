// https://codeforces.com/problemset/problem/352/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_set<int> already;
    map<int, pair<int, int>> freqs;  // x : (diff btwn occurs, last occur)
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (freqs.count(x)) {  // x already in map
            if (freqs[x].first == 0) {
                freqs[x].first = i - freqs[x].second;
            } else {
                int diff = i - freqs[x].second;
                if (diff != freqs[x].first) {
                    already.insert(x);
                    freqs.erase(x);
                    continue;
                }
            }
            freqs[x].second = i;
        } else {
            if (already.find(x) == already.end()) {
                freqs[x] = make_pair(0, i);
            }
        }
    }
    cout << freqs.size() << endl;
    for (auto p : freqs) {
        cout << p.first << ' ' << p.second.first << endl;
    }
    return 0;
}
