# http://codeforces.com/problemset/problem/139/A

n = int(input())
days = list(map(int, input().split()))
curr_day = 1
while n > 0:
    n -= days[curr_day - 1]
    if n <= 0:
        break
    curr_day = (curr_day % 7) + 1

print(curr_day)
