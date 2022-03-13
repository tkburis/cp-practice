#include <bits/stdc++.h>
using namespace std;
 
long long MOD = 1000000007;
 
int main()
{
    long long x, y, n;
    cin >> x >> y >> n;
    long long ans;
    if (n % 3 == 1) {
        ans = x;
    } else if (n % 3 == 2) {
        ans = y;
    } else if (n % 3 == 0) {
        ans = y-x;
    }
    if (n % 6 >= 4 || n % 6 == 0) {
        ans = -ans;
    }
    ans = (ans % MOD + MOD) % MOD;
    cout << ans;
    return 0;
}