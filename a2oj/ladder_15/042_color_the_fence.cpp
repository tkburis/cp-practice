#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9+7
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

typedef long long ll;

void solve()
{
    int v;
    cin >> v;
    vector<int> digits(10);
    for (int i = 1; i <= 9; i++) cin >> digits[i];
    int min = *min_element(digits.begin()+1, digits.end());
    if (min > v) {
        cout << "-1\n";
        return;
    }
    int min_digit;
    for (int i = 9; i >= 1; i--) {
        if (digits[i] == min) {
            min_digit = i;
            break;
        }
    }
    int rem = (v % min) + min;
    int i = 0;
    while (rem >= min && i < v/min) {
        for (int j = 9; j >= 1; j--) {
            if (digits[j] <= rem) {
                cout << j;
                rem -= digits[j];
                rem += min;
                i++;
                break;
            }
        }
    }
    for (int j = 0; j < v/min - i; j++) {
        cout << min_digit;
    }
    cout << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
