# https://codeforces.com/problemset/problem/227/B

n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

pos = {}
l_cnt, r_cnt = 0, 0
for i, v in enumerate(a):
    pos[v] = i + 1

for query in b:
    l_cnt += pos[query]
    r_cnt += n - pos[query] + 1

print(l_cnt, r_cnt)
