# https://codeforces.com/problemset/problem/165/A

n = int(input())
points = []
for _ in range(n):
    coord = tuple(map(int, input().split()))
    points.append(coord)
cnt = 0
for point in points:
    left, right, down, up = 0, 0, 0, 0
    for comp in points:
        if comp != point and (comp[0] == point[0] or comp[1] == point[1]):
            if comp[0] < point[0]:
                left += 1
            elif comp[0] > point[0]:
                right += 1
            elif comp[1] < point[1]:
                down += 1
            elif comp[1] > point[1]:
                up += 1
    if all(x > 0 for x in (left, right, down, up)):
        cnt += 1
print(cnt)
