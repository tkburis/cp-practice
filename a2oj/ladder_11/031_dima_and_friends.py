# https://codeforces.com/problemset/problem/272/A

n = int(input())
a = list(map(int, input().split()))

cnt = 0
for i in range(1, 6):
    if (sum(a) + i) % (n+1) != 1:
        cnt += 1
print(cnt)
