# https://codeforces.com/problemset/problem/205/A

n = int(input())
towns = list(map(int, input().split()))
mini = 1000000001
found_at = 0
cnt = 0
for i, town in enumerate(towns):
    if town < mini:
        cnt = 1
        mini = town
        found_at = i
    elif town == mini:
        cnt += 1
if cnt > 1:
    print("Still Rozdil")
else:
    print(found_at+1)
