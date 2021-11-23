// https://cses.fi/problemset/task/2205

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<bool> curr_code(n, false);
    for (bool b : curr_code) {
        cout << b;
    }
    cout << endl;
    unordered_set< vector<bool> > already;
    already.insert(curr_code);
    for (int i = 0; i < pow(2, n)-1; i++) {
        for (int j = 0; j < n; j++) {
            vector<bool> could(curr_code);
            could[j] = !could[j];
            if (already.find(could) == already.end()) {
                curr_code = could;
                already.insert(curr_code);
                break;
            }
        }
        for (bool b : curr_code) {
            cout << b;
        }
        cout << endl;
    }
    return 0;
}
