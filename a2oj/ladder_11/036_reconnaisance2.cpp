// https://codeforces.com/problemset/problem/34/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> soldiers(n);
    for (auto &i : soldiers) {
        cin >> i;
    }
    vector<int> mins;
    for (int i = 0; i < n; i++) {
        mins.push_back(abs(soldiers[i] - soldiers[(i+1) % n]));
    }
    auto min_val = *min_element(mins.begin(), mins.end());
    for (int i = 0; i < mins.size(); i++) {
        if (mins[i] == min_val) {
            if (i < mins.size()-1) {
                cout << i+1 << ' ' << i+2;
            } else {
                cout << mins.size() << ' ' << 1;
            }
            break;
        }
    }
    return 0;
}
