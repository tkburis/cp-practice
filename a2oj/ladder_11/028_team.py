# https://codeforces.com/problemset/problem/231/A

n = int(input())
cnt = 0
for _ in range(n):
    cnt += 1 if sum(list(map(int, input().split()))) >= 2 else 0
print(cnt)
