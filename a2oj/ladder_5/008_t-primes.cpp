// https://codeforces.com/problemset/problem/230/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool prime[1000001];
    memset(prime, true, sizeof(prime));
    for (int i = 2; i*i <= 1000000; i++) {
        if (prime[i]) {
            for (int j = i*i; j <= 1000000; j+=i) {
                prime[j] = false;
            }
        }
    }
    unordered_set<long long> ok;
    for (long long i = 2; i <= 1000000; i++) {
        if (prime[i]) {
            ok.insert(i*i);
        }
    }
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (ok.find(x) != ok.end()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}