// https://codeforces.com/problemset/problem/478/B

#include <bits/stdc++.h>
using namespace std;

long long pairs(long long n)
{
    if (n < 2) {
        return 0;
    }
    return (n*(n-1))/2;
}

int main()
{
    long long n, m;
    cin >> n >> m;
    long long mini = (m - (n % m)) * pairs(n/m) + (n % m) * pairs((n/m)+1);
    long long maxi = pairs(n - m + 1);
    cout << mini << ' ' << maxi;
    return 0;
}
