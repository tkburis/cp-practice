#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<char> s = {'R', 'O', 'Y', 'G'};
    for (int i = 0; i < n-3; i++) {
        cout << s[i%4];
    }
    cout << "BIV" << '\n';
    return 0;
}