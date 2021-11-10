// https://olympiad.org.uk/papers/2021/bio/bio21-exam.pdf

#include <bits/stdc++.h>
using namespace std;

bool is_pat(string s)
{
    // for given constraints naive recursion is ok, but memoization can also be utilised for bigger constraints
    int n = s.length();
    if (n == 1) {
        return true;
    }
    for (int split = 1; split < n; split++) {
        string left = s.substr(0, split);
        string right = s.substr(split, n-split);
        if (*min_element(left.begin(), left.end()) > *max_element(right.begin(), right.end())) {
            reverse(left.begin(), left.end());
            reverse(right.begin(), right.end());
            if (is_pat(left) && is_pat(right)) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    // Task 1
    string s1, s2;
    cin >> s1 >> s2;
    cout << (is_pat(s1) ? "YES" : "NO") << endl;
    cout << (is_pat(s2) ? "YES" : "NO") << endl;
    cout << (is_pat(s1+s2) ? "YES" : "NO") << endl;
    
    // Task 2
    string abcd = "ABCD";
    do {
        if (is_pat(abcd)) cout << abcd << ' ';
    } while (next_permutation(abcd.begin(), abcd.end()));
    return 0;
}
