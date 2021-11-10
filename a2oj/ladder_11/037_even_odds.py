# https://codeforces.com/problemset/problem/318/A

n, k = map(int, input().split())
if n % 2 == 0:
    f = n // 2
else:
    f = (n // 2) + 1

if k > f:
    print(2 * (k - f))
else:
    print((2 * k) - 1)
