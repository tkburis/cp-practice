# https://codeforces.com/problemset/problem/155/A

n = int(input())
a = list(map(int, input().split()))
mini = a[0]
maxi = a[0]
cnt = 0
for num in a[1:]:
    if num > maxi:
        maxi = num
        cnt += 1
    elif num < mini:
        mini = num
        cnt += 1
print(cnt)
