#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> first, second;
    ll first_sum = 0, second_sum = 0;
    bool first_last = false;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t > 0) {
            first.push_back(t);
            first_sum += t;
            first_last = true;
        } else {
            second.push_back(-t);
            second_sum -= t;
            first_last = false;
        }
    }
    if (first_sum > second_sum) {
        cout << "first" << '\n';
    } else if (first_sum < second_sum) {
        cout << "second" << '\n';
    } else {
        for (int i = 0; i < min(first.size(), second.size()); i++) {
            if (first[i] > second[i]) {
                cout << "first" << '\n';
                return 0;
            } else if (first[i] < second[i]) {
                cout << "second" << '\n';
                return 0;
            }
        }
        if (first.size() > second.size()) {
            cout << "first" << '\n';
        } else if (first.size() < second.size()) {
            cout << "second" << '\n';
        } else {
            if (first_last) cout << "first" << '\n';
            else cout << "second" << '\n';
        }
    }
    return 0;
}