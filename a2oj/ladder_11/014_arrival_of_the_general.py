# https://codeforces.com/problemset/problem/144/A

_ = input()
a = list(map(int, input().split()))
i_max = a.index(max(a))
i_min = len(a) - 1 - a[::-1].index(min(a))
s = i_max - 1 + len(a) - i_min
if i_max > i_min:
    s -= 1
print(s)
