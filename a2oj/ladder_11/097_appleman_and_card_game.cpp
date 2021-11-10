// https://codeforces.com/problemset/problem/462/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    map<char, int> cnts;
    string s;
    cin >> s;
    for (char c : s) {
        cnts[c]++;
    }
    vector<int> scores;
    for (auto p : cnts) {
        scores.push_back(p.second);
    }
    sort(scores.begin(), scores.end(), greater<>());
    long long sum = 0, i = 0;
    while (k > 0 && i < scores.size()) {
        sum += 1LL * min(k, scores[i]) * min(k, scores[i]);
        k -= min(k, scores[i]);
        i++;
    }
    cout << sum;
    return 0;
}
