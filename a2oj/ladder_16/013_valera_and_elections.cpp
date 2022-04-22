#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
map<int, vector<int>> adj;
map<pair<int, int>, bool> is_problem;

bool dfs(int curr, int parent)
{
    bool has_problem = false;
    for (int nxt : adj[curr]) {
        if (nxt != parent) {
            has_problem |= dfs(nxt, curr);
            if (is_problem[make_pair(curr, nxt)]) has_problem = true;
        }
    }
    if (is_problem[make_pair(parent, curr)] && !has_problem) {
        ans.push_back(curr);
    }
    return has_problem;
}

int main()
{
    int n, x, y, t;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y >> t;
        adj[x].push_back(y);
        adj[y].push_back(x);
        if (t == 2) {
            is_problem[make_pair(x, y)] = true;
            is_problem[make_pair(y, x)] = true;
        }
    }
    for (int nxt : adj[1]) {
        dfs(nxt, 1);
    }
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    return 0;
}
