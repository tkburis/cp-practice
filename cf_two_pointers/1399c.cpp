#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> freqs;
        set<int> w;
        for (int i = 0; i < n; i++) {
            int tt;
            cin >> tt;
            freqs[tt]++;
            w.insert(tt);
        }
        int best = 0;
        for (int s = 2; s <= 2*n; s++) {
            int cnt = 0;
            for (int i : w) {
                if (i >= ceil(s/2.0)) break;
                cnt += min(freqs[i], freqs[s-i]);
            }
            if (s % 2 == 0) {
                cnt += freqs[s/2]/2;
            }
            best = max(best, cnt);
        }
        cout << best << '\n';
    }
    return 0;
}