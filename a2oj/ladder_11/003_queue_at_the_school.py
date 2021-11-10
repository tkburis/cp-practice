# https://codeforces.com/problemset/problem/266/B

_, t = map(int, input().split())
s = input()
for _ in range(t):
    s = s.replace('BG', 'GB')
print(s)
