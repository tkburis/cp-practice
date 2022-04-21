#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, vector<ll>> adjs;
ll curr_id = 0;
vector<ll> id(100001, -1), low(100001);
vector<bool> on_stack(100001, false);
stack<ll> st;

void dfs(ll curr)
{
    st.push(curr);
    on_stack[curr] = true;
    curr_id++;
    id[curr] = curr_id;
    low[curr] = curr_id;

    for (ll nxt : adjs[curr]) {
        if (id[nxt] == -1) {
            dfs(nxt);
        }
        if (on_stack[nxt]) {
            low[curr] = min(low[nxt], low[curr]);
        }
    }

    if (id[curr] == low[curr]) {
        while (!st.empty()) {
            ll c = st.top();
            st.pop();
            on_stack[c] = false;
            id[c] = low[curr];
            if (c == curr) break;
        }
    }
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> cost(n);
    for (ll i = 0; i < n; i++) cin >> cost[i];
    ll m;
    cin >> m;
    ll a, b;
    for (ll i = 0; i < m; i++) {
        cin >> a >> b;
        adjs[a].push_back(b);
    }

    for (ll i = 1; i <= n; i++) {
        if (id[i] == -1) {
            dfs(i);
        }
    }

    map<ll, ll> id_cost, id_cnt;
    ll cnt = 1;
    for (ll i = 1; i <= n; i++) {
        if (id_cost.find(id[i]) == id_cost.end()) id_cost[id[i]] = LONG_LONG_MAX;
        id_cost[id[i]] = min(id_cost[id[i]], cost[i-1]);
    }
    for (ll i = 1; i <= n; i++) {
        if (cost[i-1] == id_cost[id[i]]) {
            id_cnt[id[i]]++;
        }
    }
    for (auto p : id_cnt) {
        cnt = (cnt * p.second) % 1000000007;
    }

    ll ans = 0;
    for (auto p : id_cost) {
        ans += p.second;
    }

    cout << ans << ' ' << cnt << '\n';

    return 0;
}