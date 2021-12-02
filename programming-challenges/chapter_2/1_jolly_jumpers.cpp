// Programming Challenges (Skiena & Revilla) - 2.8.1 Jolly Jumpers - UVa ID: 10038

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        map<int, bool> diff;
        bool jolly = true;
        for (int i = 1; i < n; i++) {
            int curr_diff = abs(nums[i] - nums[i-1]);
            if (curr_diff <= 0 || curr_diff >= n || diff[curr_diff]) {
                jolly = false;
                break;
            }
            diff[curr_diff] = true;
        }
        if (jolly) {
            cout << "Jolly\n";
        } else {
            cout << "Not jolly\n";
        }
    }
    return 0;
}

