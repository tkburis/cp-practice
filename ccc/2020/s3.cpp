#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    string n, h;
    cin >> n >> h;
    vector<int> n_cnts(26, 0);
    for (char c : n) {
        n_cnts[c-'a']++;
    }
    if (h.length() < n.length()) {
        cout << 0 << '\n';
    }
    else {
        int cnt = 0;
        map<size_t, bool> used;
        vector<int> curr_cnts(26, 0);
        for (int i = 0; i < h.length() - n.length()+1; i++) {
            string curr_sub = h.substr(i, n.length());
            if (i == 0) {
                for (char c : curr_sub) {
                    curr_cnts[c-'a']++;
                }
            } else {
                curr_cnts[h[i-1]-'a']--;
                curr_cnts[h[i+n.length()-1]-'a']++;
            }
            hash<string> hasher;
            size_t hashed = hasher(curr_sub);
            if (equal(begin(curr_cnts), end(curr_cnts), begin(n_cnts)) && !used[hashed]) {
                used[hashed] = true;
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
