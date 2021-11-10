# https://codeforces.com/problemset/problem/263/A

x, y = 0, 0
for i in range(5):
    row = list(input().split())
    if '1' in row:
        x = row.index('1')
        y = i
        break
print(abs(x-2) + abs(y-2))
