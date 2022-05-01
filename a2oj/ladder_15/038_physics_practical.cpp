#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int j = 0, best = INT_MAX;
    for (int i = 0; i < n; i++) {
        while (j < n) {
            if (a[i] * 2 < a[j]) {
                j--;
                break;
            }
            if (j+1 < n) {
                j++;
            } else {
                break;
            }
        }
        best = min(best, i+n-1-j);
    }
    cout << best << '\n';
    return 0;
}
