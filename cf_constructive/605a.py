n = int(input())
a = list(map(int, input().split()))
long_from = {}
best = 1
for x in a:
    if x-1 in long_from:
        long_from[x] = long_from[x-1] + 1
    else:
        long_from[x] = 1
print(n - max(long_from.values()))
