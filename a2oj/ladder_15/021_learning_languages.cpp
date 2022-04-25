#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> adj;
    int k, a;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> a;
            adj[i].push_back(n+a);
            adj[n+a].push_back(i);
        }
    }
    if (adj.size() == 0) {
        cout << n << '\n';
        return 0;
    }
    int curr, comps = 0;
    vector<bool> vis(n+m+1, false);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            comps++;
            q.push(i);
            while (!q.empty()) {
                curr = q.front(); q.pop();
                vis[curr] = true;
                for (int nxt : adj[curr]) {
                    if (!vis[nxt]) q.push(nxt);
                }
            }
        }
    }
    cout << comps-1 << '\n';
    return 0;
}