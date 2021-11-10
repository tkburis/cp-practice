# https://codeforces.com/problemset/problem/266/A

_ = input()
s = list(input())

n = 0
for i in range(len(s)-1):
    if s[i] == s[i+1]:
        n += 1
print(n)
