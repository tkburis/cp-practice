#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    map<char, int> freqs;
    for (char c : s) freqs[c]++;
    int odds = 0;
    for (auto p : freqs) {
        if (p.second % 2 == 1) odds++;
    }
    if (odds < 2) {
        cout << "First" << '\n';
    } else {
        if (odds % 2 == 0) {
            cout << "Second" << '\n';
        } else {
            cout << "First" << '\n';
        }
    }
    return 0;
}