#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int lt = 0;
    for (int i = 0; i < n-1; i++) {
        if (a[i] > a[i+1]) lt++;
    }
    if (a[n-1] > a[0]) lt++;
    if (lt == 0) {
        cout << 0 << '\n';
    } else if (lt > 1) {
        cout  << -1 << '\n';
    } else {
        int maxi = *max_element(a.begin(), a.end());
        int mini = *min_element(a.begin(), a.end());
        int idx = n-1;
        for (int i = 0; i < n-1; i++) {
            if (a[i] == maxi && a[i+1] == mini) {
                idx = i;
                break;
            }
        }
        cout << n-idx-1 << '\n';
    }
    return 0;
}
