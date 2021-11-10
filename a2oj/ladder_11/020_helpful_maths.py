# https://codeforces.com/problemset/problem/339/A

s = list(map(int, input().split('+')))
t = '+'.join(list(map(str, sorted(s))))
print(t)
