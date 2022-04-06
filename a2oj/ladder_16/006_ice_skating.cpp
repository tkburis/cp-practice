#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> coords(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        coords[i] = make_pair(x, y);
    }
    sort(coords.begin(), coords.end());
    map<pair<int, int>, bool> ok;
    map<pair<int, int>, vector<pair<int, int>>> adjs;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (coords[i].first == coords[j].first || coords[i].second == coords[j].second) {
                adjs[coords[i]].push_back(coords[j]);
                adjs[coords[j]].push_back(coords[i]);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!ok[coords[i]]) {
            if (i > 0) cnt++;
            ok[coords[i]] = true;

            queue<pair<int, int>> q;
            set<pair<int, int>> vis;
            q.push(coords[i]);
            vis.insert(coords[i]);
            while (!q.empty()) {
                pair<int, int> curr = q.front();
                q.pop();
                for (auto adj : adjs[curr]) {
                    if (vis.find(adj) == vis.end()) {
                        ok[adj] = true;
                        q.push(adj);
                        vis.insert(adj);
                    }
                }
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
