#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    vector<int> af, bf;
    for (int i = 1; i*i <= a; i++) {
        if (a % i == 0) {
            if (i != a/i) {
                af.push_back(a/i);
            }
            af.push_back(i);
        }
    }
    for (int i = 1; i*i <= b; i++) {
        if (b % i == 0) {
            if (i != b/i) {
                bf.push_back(b/i);
            }
            bf.push_back(i);
        }
    }
    sort(af.begin(), af.end());
    sort(bf.begin(), bf.end());
    vector<int> cds;
    set_intersection(af.begin(), af.end(), bf.begin(), bf.end(), back_inserter(cds));
    int n;
    cin >> n;
    while (n--) {
        int low, high;
        cin >> low >> high;
        int ub = cds[upper_bound(cds.begin(), cds.end(), high) - cds.begin() - 1];
        if (ub >= low) {
            cout << ub << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}
