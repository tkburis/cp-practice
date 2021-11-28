// Programming Challenges (Skiena & Revilla) - 1.6.3 The Trip - UVa ID: 10137

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        vector<double> students(n);
        double total = 0;
        for (int i = 0; i < n; i++) {
            cin >> students[i];
            total += students[i];
        }
        double avg = total / n;
        double give = 0, take = 0;
        for (int i = 0; i < n; i++) {
            double diff = (double)(int)((students[i] - avg) * 100.0) / 100.0;
            if (diff < 0) {
                give += diff;
            } else {
                take += diff;
            }
        }
        cout << fixed << setprecision(2);
        if (-give > take) {
            cout << '$' << -give << '\n';
        } else {
            cout << '$' << take << '\n';
        }
    }
    return 0;
}

