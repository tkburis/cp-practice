# https://codeforces.com/problemset/problem/148/A

k = int(input())
l = int(input())
m = int(input())
n = int(input())
d = int(input())
mults = (k, l, m, n)
cnt = 0

for i in range(1, d+1):
    if any(i % x == 0 for x in mults):
        cnt += 1

print(cnt)
