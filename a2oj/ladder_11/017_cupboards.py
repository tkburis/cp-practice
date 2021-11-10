# https://codeforces.com/problemset/problem/248/A

n = int(input())
l_cnt = 0
r_cnt = 0
for _ in range(n):
    counts = list(map(int, input().split()))
    l_cnt += counts[0]
    r_cnt += counts[1]

total = min(l_cnt, n - l_cnt) + min(r_cnt, n - r_cnt)
print(total)
