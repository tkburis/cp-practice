#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> chain = {a[0]};
    for (int i = 1; i < n; i++) {
        if (a[i] > chain.back()) {
            chain.push_back(a[i]);
        } else {
            int idx = lower_bound(chain.begin(), chain.end(), a[i]) - chain.begin();
            chain[idx] = a[i];
        }
        // for (int x : chain) cout << x << ' ';
        // cout << '\n';
    }
    cout << chain.size() << '\n';
    return 0;
}
