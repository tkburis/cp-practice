# https://codeforces.com/problemset/problem/69/A

n = int(input())
fs = [0, 0, 0]
for _ in range(n):
    _input = map(int, input().split())
    fs = [sum(x) for x in zip(_input, fs)]

if all(x == 0 for x in fs):
    print('YES')
else:
    print('NO')
