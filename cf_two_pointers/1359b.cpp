#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        vector<int> white_rows;
        for (int i = 0; i < n; i++) {
            string row;
            cin >> row;
            int curr = 0;
            for (int j = 0; j < m; j++) {
                if (row[j] == '.') {
                    curr++;
                } else {
                    if (curr > 0) white_rows.push_back(curr);
                    curr = 0;
                }
            }
            if (row[m-1] == '.') white_rows.push_back(curr);
        }
        vector<int> mini(m+1);  // mini[i] = min cost to cover i tiles in a row
        mini[0] = 0;
        mini[1] = x;
        for (int i = 2; i <= m; i++) {
            mini[i] = min(mini[i-2] + min(2*x, y), mini[i-1] + x);
        }
        int s = 0;
        for (int r : white_rows) s += mini[r];
        cout << s << '\n';
    }
    return 0;
}
