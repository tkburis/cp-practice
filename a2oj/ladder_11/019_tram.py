# https://codeforces.com/problemset/problem/116/A

n = int(input())
movements = []
for _ in range(n):
    movements.append(list(map(int, input().split())))
maxi = 0
curr = 0
for movement in movements:
    curr += movement[1] - movement[0]
    maxi = max(maxi, curr)

print(maxi)
