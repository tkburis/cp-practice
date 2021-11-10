/*
Programming Challenges (Skiena & Revilla) - 1.6.1 The 3n+1 Problem
UVa ID: 100
Status: Accepted
*/

#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> cycle_lengths;

// Performs a single '3n+1' operation
int next(int n)
{
    if (n % 2 == 0) {
        return n / 2;
    } else {
        return 3*n + 1;
    }
}

// Recursively finds cycle length, while memoizing results into cycle_lengths
int get_cycle_length(int n)
{
    // Recursive base case
    if (n == 1) {
        return 1;
    }
    // If a result has already been memoized, use it
    if (cycle_lengths[n] != 0) {
        return cycle_lengths[n];
    } else {
        // If not, recurse to find it
        cycle_lengths[n] = get_cycle_length(next(n)) + 1;
        return cycle_lengths[n];
    }
}

int solve(int i, int j)
{
    // Judge might try to give i > j
    if (i > j) {
        swap(i, j);
    }
    int maxi = 0;
    for (int n = i; n <= j; n++) {
        maxi = max(maxi, get_cycle_length(n));
    }
    return maxi;
}

int main()
{
    int i, j;
    while (scanf("%d %d", &i, &j) != EOF) {
        printf("%d %d %d\n", i, j, solve(i, j));
    }
    return 0;
}
