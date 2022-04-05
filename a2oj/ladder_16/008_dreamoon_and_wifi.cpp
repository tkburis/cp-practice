#include <bits/stdc++.h>
using namespace std;

float fact(int n)
{
    float ret = 1.0;
    for (int i = 2; i <= n; i++) ret *= i;
    return ret;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int num_plus = 0, num_minus = 0;
    for (char c : s1) {
        if (c == '+') num_plus++;
        else if (c == '-') num_minus++;
    }
    int already_plus = 0, already_minus = 0;
    for (char c : s2) {
        if (c == '+') already_plus++;
        else if (c == '-') already_minus++;
    }
    int need_plus = num_plus - already_plus, need_minus = num_minus - already_minus;
    if (need_plus < 0 || need_minus < 0) {
        cout << 0 << '\n';
    } else if (need_plus == 0 && need_minus == 0) {
        cout << 1 << '\n';
    } else {
        int qs = n - already_plus - already_minus;
        cout << setprecision(10) << (fact(qs) / (fact(need_plus) * fact(qs - need_plus))) / pow(2, qs) << '\n';
    }
    return 0;
}
