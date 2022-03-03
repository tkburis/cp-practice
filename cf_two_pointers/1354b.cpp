#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();

        vector<int> has(4, 0);
        int best = 1000000;
        int i = 0, j = 0;
        has[s[0]-'0']++;

        while (j < n) {
            if (has[1] > 0 && has[2] > 0 && has[3] > 0) {
                best = min(best, j - i + 1);
                has[s[i]-'0']--;
                i++;
            } else {
                if (j + 1 < n) {
                    j++;
                    has[s[j]-'0']++;
                } else {
                    break;
                }
            }
        }
        if (best == 1000000) cout << 0 << '\n';
        else cout << best << '\n';
    }
    return 0;
}