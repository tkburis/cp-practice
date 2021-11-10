# https://codeforces.com/problemset/problem/450/A
from math import ceil

n, m = map(int, input().split())
a = list(map(int, input().split()))
a = [ceil(x/m) for x in a]

for i in range(len(a)-1, -1, -1):
    if a[i] == max(a):
        print(i+1)
        break
