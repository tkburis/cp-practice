// https://codeforces.com/problemset/problem/431/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int g[6][6];
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 6; j++) {
            cin >> g[i][j];
        }
    }
    int line[5] = {1, 2, 3, 4, 5}, maxi = -1;
    do {
        int curr = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = i; j < 4; j += 2) {
                curr += g[line[j]][line[j+1]] + g[line[j+1]][line[j]];
            }
        }
        maxi = max(maxi, curr);
    } while (next_permutation(line, line+5));
    cout << maxi;
    return 0;
}
